---
created: 2025-01-17T15:59
updated: 2025-01-17T16:30
---

## Inleiding
Voor het software gedeelte van de poortaalkraan hebben we ervoor gekozen om alle functies van de portaalkraan op te delen in header bestanden zodat je voor elke functie aparte testen uit kan voeren en deze kan can combineren. Dit zorgt ervoor dat de main c file er overzichtelijk uitziet en dat je makkelijker individuele onderdelen kan testen. Daarnaast hebben we de pins gedefinieerd aan het begin van het bestand zodat de code leesbaarder is.

## Motor.h
### Init
Voor de motor hebben we als eerst de init functies, deze zetten alle benodigde pins als output, en zet de benodigde timers aan.

### Bewegen
Voor het bewegen van de motoren hebben we gekozen voor de richtingen: links, rechts, omhoog en omlaag. Deze richtingen zijn weergeven in functies die als doel hebben om de juiste pwm-pins aan te zetten.

### Stop
En ten slotte de stop functie deze stopt alle bewegingen. Door alle pwm-pins op laag te zetten.
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
#define vcc1 PA0    // Pin 22: Algemene uitgang
#define vcc2 PA1    // Pin 23: Algemene uitgang
#define uint_8t richting

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

## LimitSwitch.h
### Inleiding
Voor de limit switches hebben we 2 functies een voor aangeven of de switch is ingedrukt en een andere voor het tellen van de kliks. De reden dat we dit hebben gedaan is omdat we voor beide assen de beweging controleren d.m.v. de limit switches.

### isLimitSwitchPressed 
Deze functie geeft een integer terug van 1 of 0; waarbij 1 aangeeft dat de switch is ingedrukt en 0 dat deze niet is ingedrukt. We geven bij deze functie de pin, port, en het pin register mee. We hebben hiervoor gekozen zodat deze functie herbruikbaar is voor meerdere limit switches. Dit is handig omdat wij enkel limit switches gebruiken als sensoren voor de portaalkraan.

### countLimitSwitchPresses 
Zoals de naam aangeeft telt deze functie het aantal keer dat de limit switch is ingedrukt. Maar niet zomaar we hebben in deze functie rekening gehouden met de richting waarin de kraan beweegt.
Dit zorgt ervoor dat als de kraan naar rechts beweegt dan zal de teller omhoog gaan, maar als de kraan naar links beweegt dan zal de teller omlaag gaan.
```c
#ifndef LIMIT_SWITCH_H
#define LIMIT_SWITCH_H

#include <avr/io.h>
#include <util/delay.h>

// Function prototypes
int isLimitSwitchPressed(uint8_t inputPin, volatile uint8_t *inputPort, volatile uint8_t *pinReg);
uint16_t countLimitSwitchPresses(uint8_t inputPin, volatile uint8_t *inputPort, volatile uint8_t *pinReg);

#endif // LIMIT_SWITCH_H
```

## Portaalkraan.h
### Inleiding
Om alle deelfuncties samen te voegen tot hoofdfuncties hebben we gekozen om nog een bestand te maken voor de portaalkraan als geheel.

### init
Bij het initialiseren van de portaalkraan roepen we alle andere init functies op

### nulpuntPortaalkraan 
De functie nulpuntPortaalkraan laat de motor draaien zodat de kraan zich naar links verplaats deze stopt zodra de limit switch is geraakt. Het huidige coördinaat zal dan worden aangepast naar 0. Dit is hetzelfde coördinaat wat de countLimitSwitchPresses functie gebruikt. Ook zal de z-as omhoog gaan tot de limit switch is geraakt. Dit doen we d.m.v het gebruiken van de motor en limit switch functies.

### afstandPortaalkraan
Deze functie gebruikt de countLimitSwitchPresses functie om een int terug te geven die aangeeft hoe vaak de limit switch is ingedrukt dit is dan ook het y-coördinaat.

### Magneet
#### portaalkraanMagneetAan
Deze functie zet de pin van de magneet op hoog zodat deze aan staat.

#### portaalkraanMagneetUit 
Deze functie zet de pin van de magneet op laag zodat deze uit staat.

### Oppakken van de potplant
#### pakPotplantOp
Deze functie laat de z-as naar beneden draaien totdat de limit switch wordt geraakt, ook gaat de elektromagneet aan. Daarna gaat de z-as weer draaien zodat deze omhoog gaat. Dit doen we d.m.v. het gebruiken van de motor en limit switch functies.

#### zetPotplantNeer
Deze functie laat de z-as naar beneden draaien totdat de limit switch wordt geraakt, dan gaat de magneet uit. Daarna gaat de z-as weer draaien zodat deze omhoog gaat. Dit doen we d.m.v. het gebruiken van de motor en limit switch functies.
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
uint16_t afstandPortaalkraan();

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

/**
 * @brief Zet een potplant neer door de kraan naar beneden te bewegen
 *        totdat de limietschakelaar wordt geactiveerd, daarna wordt de magneet uitgeschakeld.
 */
void zetPotplantNeer(void)
#endif // PORTAALKRAAN_H

```