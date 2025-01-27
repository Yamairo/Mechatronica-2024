---
created: 2025-01-17T00:30
updated: 2025-01-17T11:26
---
```toc
```

## LimitSwitch Code
### LimitSwitch.h

```c
#ifndef LIMIT_SWITCH_H
#define LIMIT_SWITCH_H

#include <avr/io.h>

// Function prototypes
int isLimitSwitchPressed(uint8_t inputPin, volatile uint8_t *inputPort, volatile uint8_t *pinReg);
uint16_t countLimitSwitchPresses(uint8_t inputPin, volatile uint8_t *inputPort, volatile uint8_t *pinReg);

#endif // LIMIT_SWITCH_H

```

### LimitSwitch.c

```c
/**
 * @brief Tel het aantal keren dat een limietschakelaar wordt geactiveerd,
 *        en pas de teller aan op basis van de bewegingsrichting.
 *
 * @param inputPin De pin van de limietschakelaar.
 * @param inputPort De poort waaraan de limietschakelaar is verbonden.
 * @param pinReg Het pinregister voor het lezen van de limietschakelaarstatus.
 * @param richting De bewegingsrichting: -1 voor links, +1 voor rechts.
 * @return De bijgewerkte waarde van de teller.
 */
uint16_t countLimitSwitchPresses(uint8_t inputPin, volatile uint8_t *inputPort, volatile uint8_t *pinReg, int8_t richting) {
    static int16_t pressCount = 0; // Persistent teller van activaties (kan negatief worden)
    static uint8_t wasPressed = 0; // Houdt de vorige status van de knop bij

    // Configureer de input pin met een pull-up weerstand
    *inputPort |= (1 << inputPin); // Schakel pull-up weerstand in

    // Controleer of de knop momenteel is ingedrukt
    if (!(*pinReg & (1 << inputPin))) { // Knop is ingedrukt
        if (!wasPressed) { // Detecteer overgang van niet-ingedrukt naar ingedrukt
            pressCount += richting; // Pas de teller aan op basis van de richting
            wasPressed = 1;         // Markeer de knop als ingedrukt
            _delay_ms(50);          // Simpele debounce-vertraging
        }
    } else { // Knop is niet ingedrukt
        wasPressed = 0; // Reset de ingedrukte status
    }

    // Zorg ervoor dat de teller niet negatief wordt als je dat wilt vermijden
    if (pressCount < 0) {
        pressCount = 0;
    }

    return (uint16_t)pressCount; // Geef de tellerwaarde terug als unsigned integer
}

```

## Motor Code

### Motor.h
```c
#ifndef MOTOR_H
#define MOTOR_H

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

// Pin-definities voor motorbediening
#define LPWM PL5  // Pin 44: Links PWM (voor horizontale beweging)
#define RPWM PL3  // Pin 46: Rechts PWM (voor horizontale beweging)
#define LPWM2 PL4 // Pin 45: Links PWM2 (voor verticale beweging)
#define RPWM2 PL2 // Pin 47: Rechts PWM2 (voor verticale beweging)
#define v5 PA0    // Pin 22: Algemene uitgang (bijvoorbeeld voeding of statusled)

// Functieprototypes

/**
 * @brief Initialiseer de timer (Timer0) voor PWM-controle.
 *        Dit omvat het instellen van de timer-modus, prescaler en interrupts
 *        die nodig zijn voor motorbediening.
 */
void init_timer(void);

/**
 * @brief Configureer de benodigde pins voor motorbesturing.
 *        Stelt pin-modi in (input/output) en schakelt pull-up weerstanden in waar nodig.
 */
void init_pins(void);

/**
 * @brief Initialiseer zowel de timer als de pins.
 *        Zorgt ervoor dat de hardware correct is ingesteld voordat de motor wordt gebruikt.
 */
void init(void);

// Interrupt Service Routines (ISRs)

/**
 * @brief ISR voor Compare Match A van Timer0.
 *        Deze routine schakelt de actieve PWM-signalen uit (laag) wanneer een compare match plaatsvindt.
 */
ISR(TIMER0_COMPA_vect);

/**
 * @brief ISR voor Overflow van Timer0.
 *        Deze routine schakelt de actieve PWM-signalen in (hoog) bij een overflow van Timer0.
 */
ISR(TIMER0_OVF_vect);

/**
 * @brief Activeer PWM voor de LPWM-pin (Pin 44).
 *        Dit zorgt ervoor dat de motor naar links beweegt.
 */
void motorBeweegLinks(void);

/**
 * @brief Activeer PWM voor de RPWM-pin (Pin 47).
 *        Dit zorgt ervoor dat de motor naar beneden beweegt.
 */
void motorBeweegOmlaag(void);

/**
 * @brief Activeer PWM voor de LPWM2-pin (Pin 45).
 *        Dit zorgt ervoor dat de motor naar boven beweegt.
 */
void motorBeweegOmhoog(void);

/**
 * @brief Schakel alle motoruitgangen uit (LPWM, RPWM, LPWM2, RPWM2).
 *        Dit stopt alle bewegingen van de motor.
 */
void motorStop(void);

#endif // MOTOR_H
```

### Motor.c
```c
#include "motor.h"

// Globale variabelen om de motorstatus bij te houden
volatile uint8_t lpwm_active = 0;  // Links PWM actief
volatile uint8_t rpwm_active = 0;  // Rechts PWM actief
volatile uint8_t lpwm2_active = 0; // Links PWM2 actief (voor omhoog/omlaag)
volatile uint8_t rpwm2_active = 0; // Rechts PWM2 actief (voor omhoog/omlaag)

/**
 * @brief Initialiseer de timer (Timer0) voor motorbediening.
 *        - Zet de timer in Normal mode.
 *        - Gebruik een prescaler van 64.
 *        - Stel een duty cycle in van 50%.
 *        - Schakel Compare Match A en Overflow interrupts in.
 */
void init_timer(void)
{
    // Zet Timer0 in Normal mode, Prescaler = 64
    TCCR0A = 0; // Normal mode
    TCCR0B = (0 << CS02) | (1 << CS01) | (1 << CS00); // Prescaler = 64

    OCR0A = 127;  // Duty cycle van 50%
    TIMSK0 = (1 << OCIE0A) | (1 << TOIE0); // Schakel Compare Match A en Overflow interrupts in
}

/**
 * @brief Initialiseer alle benodigde pins voor motorbediening en debugfuncties.
 *        - Stel pin PB6 in als uitgang voor debug LED.
 *        - Stel motorbedieningspins (LPWM, RPWM) in als uitgangen en zet deze uit.
 *        - Stel pin 22 in als uitgang.
 *        - Stel PF1 in als invoer met pull-up weerstand (bijvoorbeeld voor een knop).
 */
void init_pins(void)
{
    // Debug LED instellen
    DDRB |= (1 << PB6);

    // Motorbedieningspins (LPWM, RPWM) instellen als uitgangen, standaard uitgeschakeld
    DDRL |= (1 << LPWM) | (1 << RPWM);
    PORTL &= ~(1 << LPWM) & ~(1 << RPWM);

    // Pin 22 (v5) instellen als uitgang
    DDRA |= (1 << v5);

    // PF1 (knop) instellen als invoer met pull-up weerstand
    DDRF &= ~(1 << PF1);  // PF1 als invoer
    PORTF |= (1 << PF1);  // Pull-up weerstand inschakelen
}

/**
 * @brief Initialiseer de motorbediening door pins en timers in te stellen.
 *        Schakel globale interrupts in.
 */
void init(void)
{
    init_pins();    // Pins initialiseren
    init_timer();   // Timer initialiseren
    sei();          // Schakel globale interrupts in
}

/**
 * @brief Beweeg de motor naar links door LPWM te activeren en RPWM te deactiveren.
 */
void motorBeweegLinks(void)
{
    lpwm_active = 1; // LPWM inschakelen
    rpwm_active = 0; // RPWM uitschakelen
}

/**
 * @brief Beweeg de motor naar rechts door RPWM te activeren en LPWM te deactiveren.
 */
void motorBeweegRechts(void)
{
    rpwm_active = 1; // RPWM inschakelen
    lpwm_active = 0; // LPWM uitschakelen
}

/**
 * @brief Beweeg de motor naar beneden door RPWM2 te activeren en LPWM2 te deactiveren.
 */
void motorBeweegOmlaag(void)
{
    rpwm2_active = 1; // RPWM2 inschakelen
    lpwm2_active = 0; // LPWM2 uitschakelen
}

/**
 * @brief Beweeg de motor omhoog door LPWM2 te activeren en RPWM2 te deactiveren.
 */
void motorBeweegOmhoog(void)
{
    lpwm2_active = 1; // LPWM2 inschakelen
    rpwm2_active = 0; // RPWM2 uitschakelen
}

/**
 * @brief Stop alle motoren door alle PWM-signalen uit te schakelen.
 */
void motorStop(void)
{
    lpwm_active = 0;  // LPWM uitschakelen
    rpwm_active = 0;  // RPWM uitschakelen
    lpwm2_active = 0; // LPWM2 uitschakelen
    rpwm2_active = 0; // RPWM2 uitschakelen

    // Zet alle motorpins uit
    PORTL &= ~(1 << LPWM) & ~(1 << RPWM) & ~(1 << LPWM2) & ~(1 << RPWM2);
}

/**
 * @brief ISR (Interrupt Service Routine) voor Timer0 Compare Match A.
 *        Zet de actieve motorpins uit (PWM-signaal laag).
 */
ISR(TIMER0_COMPA_vect)
{
    if (lpwm_active)
    {
        PORTL &= ~(1 << LPWM); // LPWM uitschakelen
    }
    if (rpwm_active)
    {
        PORTL &= ~(1 << RPWM); // RPWM uitschakelen
    }
    if (lpwm2_active)
    {
        PORTL &= ~(1 << LPWM2); // LPWM2 uitschakelen
    }
    if (rpwm2_active)
    {
        PORTL &= ~(1 << RPWM2); // RPWM2 uitschakelen
    }
}

/**
 * @brief ISR (Interrupt Service Routine) voor Timer0 Overflow.
 *        Zet de actieve motorpins aan (PWM-signaal hoog).
 */
ISR(TIMER0_OVF_vect)
{
    if (lpwm_active)
    {
        PORTL |= (1 << LPWM); // LPWM inschakelen
    }
    if (rpwm_active)
    {
        PORTL |= (1 << RPWM); // RPWM inschakelen
    }
    if (lpwm2_active)
    {
        PORTL |= (1 << LPWM2); // LPWM2 inschakelen
    }
    if (rpwm2_active)
    {
        PORTL |= (1 << RPWM2); // RPWM2 inschakelen
    }
}
```

## Portaalkraan Code
### Portaalkraan.h
```c
#ifndef PORTAALKRAAN_H
#define PORTAALKRAAN_H

#include <stdint.h>

/**
 * @brief Initialiseer alle pins zodat de portaalkraan volledig werkt.
 *        Dit omvat het instellen van de juiste pin-modi en het activeren
 *        van eventuele pull-up weerstanden.
 */
void initPortaalkraan(void);

/**
 * @brief Beweeg naar links tot de limietschakelaar wordt geactiveerd
 *        en stel het huidige coördinaat op 0 in.
 *        Dit nulpunt dient als referentiepunt voor verdere bewegingen.
 */
void nulpuntPortaalkraan(void);

/**
 * @brief Tel het aantal keren dat de limietschakelaar op de y-as wordt geactiveerd.
 *        Dit aantal wordt teruggegeven als een geheel getal (uint16_t)
 *        en stelt het huidige y-coördinaat van de portaalkraan voor.
 *
 * @return Het huidige y-coördinaat (aantal activeringen van de limietschakelaar).
 */
uint16_t afstandPortaalkraan(void);

/**
 * @brief Schakel de magneet van de portaalkraan in om objecten vast te houden.
 *        Dit kan bijvoorbeeld worden gebruikt om een potplant op te pakken.
 */
void portaalkraanMagneetAan(void);

/**
 * @brief Schakel de magneet van de portaalkraan uit om objecten los te laten.
 */
void portaalkraanMagneetUit(void);

/**
 * @brief Pak een potplant op door de kraan naar beneden te bewegen
 *        totdat de limietschakelaar wordt geactiveerd, terwijl de magneet wordt ingeschakeld.
 */
void pakPotplantOp(void);

#endif // PORTAALKRAAN_H

```

### Portaalkraan.c
```c
#include "Portaalkraan.h" // Headerbestand voor Portaalkraan functies
#include "LimitSwitch.h"  // Headerbestand voor limietschakelaar functionaliteit
#include "Motor.h"        // Headerbestand voor motorbediening
#include <avr/io.h>       // AVR I/O definities
#include <util/delay.h>   // Voor het toevoegen van vertragingen

// Variabele om de afgelegde afstand bij te houden
static uint16_t distanceCount = 0;

/**
 * Functie om de portaalkraan te initialiseren
 */
void initPortaalkraan(void) {
    init(); // Initialiseer motorbesturing

    // Stel PB0, PB1, PB2 in als ingangen voor de limietschakelaars
    DDRB &= ~(1 << PB0) & ~(1 << PB1) & ~(1 << PB2);

    // Activeer pull-up weerstanden op PB0, PB1 en PB2
    PORTB |= (1 << PB0) | (1 << PB1) | (1 << PB2);
}

/**
 * Functie om het nulpunt van de portaalkraan te bepalen
 */
void nulpuntPortaalkraan(void) {
    motorBeweegLinks(); // Beweeg de motor naar links richting het nulpunt

    // Blijf bewegen totdat de limietschakelaar (PB0) is ingedrukt
    while (!isLimitSwitchPressed(PB0, &PORTB, &PINB)) {
        _delay_ms(1); // Controleer elke milliseconde
    }

    motorStop(); // Stop de motor zodra het nulpunt is bereikt
    motorBeweegRechts(); // Beweeg een klein stukje naar rechts
    _delay_ms(10);       // Wacht 10 ms
    motorStop();         // Stop de motor

    distanceCount = 0;   // Reset de afstandsteller
}

/**
 * Functie om een potplant op te pakken
 */
void pakPotplantOp(void) {
    portaalkraanMagneetAan(); // Activeer de magneet om de potplant op te pakken
    motorBeweegOmlaag();      // Beweeg de motor naar beneden
    // Blijf bewegen totdat de onderste limietschakelaar (PB2) is ingedrukt
    while (!isLimitSwitchPressed(PB2, &PORTB, &PINB)) {
        _delay_ms(1); // Controleer elke milliseconde
    }
    motorStop();
    portaalkraanMagneetAan();
    motorBeweegOmhoog();
    while (!isLimitSwitchPressed(PB3, &PORTB, &PINB)) {
        _delay_ms(1); // Controleer elke milliseconde
    }
    motorStop();
}

void zetPotplantNeer(void) {
    motorBeweegOmlaag();      // Beweeg de motor naar beneden
    // Blijf bewegen totdat de onderste limietschakelaar (PB2) is ingedrukt
    while (!isLimitSwitchPressed(PB2, &PORTB, &PINB)) {
        _delay_ms(1); // Controleer elke milliseconde
    }
    motorStop();
    portaalkraanMagneetUit();
    motorBeweegOmhoog();
    while (!isLimitSwitchPressed(PB3, &PORTB, &PINB)) {
        _delay_ms(1); // Controleer elke milliseconde
    }
    motorStop();
}

/**
 * Functie om de afgelegde afstand van de portaalkraan op te vragen
 * @return De totale afstand (aantal limietschakelaar-activeringen)
 */
uint16_t afstandPortaalkraan(void) {
    return countLimitSwitchPresses(PB1, &PORTB, &PINB); // Geef het totaal aantal limietschakelaar-activeringen terug
}

/**
 * Functie om de magneet van de portaalkraan aan te zetten
 */
void portaalkraanMagneetAan(void) {
    // Deze functie activeert de magneet, implementatie ontbreekt
}

```

## Main
### Main.c
```c
#include "Portaalkraan.h"
#include <avr/io.h>
#include <util/delay.h>

static uint16_t distanceCount = 0; // Houdt de afgelegde afstand bij

int main(void) {
    initPortaalkraan(); // Initialiseer het systeem
    nulpuntPortaalkraan(); // Beweeg naar het nulpunt

    while (1) {
        uint16_t distance = afstandPortaalkraan(); // Lees de huidige afstand

        motorBeweegRechts(); // Beweeg de kraan naar rechts

        // Controleer of de afstand 10 eenheden is
        if (distance == 10) {
            motorStop();       // Stop de motor
            pakPotplantOp();   // Pak de potplant op
            motorBeweegRechts(); // Ga verder naar rechts
        }

        // Controleer of de afstand 30 eenheden is
        if (distance == 30) {
            motorStop();         // Stop de motor
            zetPotplantNeer();   // Zet de potplant neer
            nulpuntPortaalkraan(); // Keer terug naar het nulpunt
            exit();
        }
    }

    return 0; // Bereik dit nooit
}
```