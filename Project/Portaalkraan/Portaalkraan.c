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