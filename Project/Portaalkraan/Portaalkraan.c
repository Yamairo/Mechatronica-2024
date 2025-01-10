#include "Portaalkraan.h"
#include "LimitSwitch.h"
#include "Motor.h"
#include <avr/io.h>
#include <util/delay.h>

static uint16_t distanceCount = 0; // Tracks the distance traveled

void initPortaalkraan(void) {
    // Initialize motor and limit switches
    init(); // Initialize motor control
    DDRB &= ~(1 << PB0) & ~(1 << PB1) & ~(1 << PB2); // PB0, PB1, PB2 as inputs for limit switches
    PORTB |= (1 << PB0) | (1 << PB1) | (1 << PB2);  // Enable pull-up resistors
}

void nulpuntPortaalkraan(void) {
    // Move motor until the zero-point limit switch (PB0) is triggered
    motorBeweegRechts(); // Move motor in one direction
    while (!isLimitSwitchPressed(PB0, &PORTB, &PINB)) {
        _delay_ms(10); // Check every 10ms
    }
    motorStop(); // Stop motor when zero point is reached
    distanceCount = 0; // Reset the distance count
}

uint16_t afstandPortaalkraan(void) {
    // Monitor the distance counting limit switch (PB1)
    if (isLimitSwitchPressed(PB1, &PORTB, &PINB)) {
        distanceCount++; // Increment the distance count on each trigger
    }
    return distanceCount; // Return the total distance count
}

void portaalkraanMagneet(void) {
    // Check if the magnet safety limit switch (PB2) is triggered
    if (isLimitSwitchPressed(PB2, &PORTB, &PINB)) {
        // Add code to turn off the magnet here
        // Example: Setting a magnet control pin low
        PORTB &= ~(1 << PB4); // Assume PB4 controls the magnet
    }
}
