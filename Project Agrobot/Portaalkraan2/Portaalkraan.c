
#include "Portaalkraan.h" // Headerbestand voor Portaalkraan functies
#include "LimitSwitch.h"  // Headerbestand voor limietschakelaar functionaliteit
#include "Motor.h"        // Headerbestand voor motorbediening
#include <avr/io.h>       // AVR I/O definities
#include <util/delay.h>   // Voor het toevoegen van vertragingen

static uint16_t distanceCount = 0; // Tracks the distance traveled


/**
 * Functie om de portaalkraan te initialiseren
 */
void initPortaalkraan(void) {
    // Initialize motor and limit switches
    init(); // Initialize motor control
    DDRB &= ~(1 << PB0) & ~(1 << PB1) & ~(1 << PB2); // PB0, PB1, PB2 as inputs for limit switches
    PORTB |= (1 << PB0) | (1 << PB1) | (1 << PB2);  // Enable pull-up resistors
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
    // Move motor until the zero-point limit switch (PB0) is triggered
    motorBeweegLinks(); // Move motor in one direction
    motorBeweegLinks(); // Beweeg de motor naar links richting het nulpunt

    // Blijf bewegen totdat de limietschakelaar (PB0) is ingedrukt
    while (!isLimitSwitchPressed(PB0, &PORTB, &PINB)) {
        _delay_ms(10); // Check every 10ms
        _delay_ms(1); // Controleer elke milliseconde
    }
    motorStop(); // Stop motor when zero point is reached
    motorBeweegRechts();
    _delay_ms(10);
    motorStop();
    distanceCount = 0; // Reset the distance count

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
    return countLimitSwitchPresses(PB1, &PORTB, &PINB); // Return the total distance count
    return countLimitSwitchPresses(PB1, &PORTB, &PINB); // Geef het totaal aantal limietschakelaar-activeringen terug
}

void portaalkraanMagneet(void) {
    // Check if the magnet safety limit switch (PB2) is triggered
    if (isLimitSwitchPressed(PB2, &PORTB, &PINB)) {
        // Add code to turn off the magnet here
        // Example: Setting a magnet control pin low
        PORTB &= ~(1 << PB4); // Assume PB4 controls the magnet
    }
}
/**
 * Functie om de magneet van de portaalkraan aan te zetten
 */
void portaalkraanMagneetAan(void) {
    // Deze functie activeert de magneet, implementatie ontbreekt
}
