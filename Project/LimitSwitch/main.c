#include "LimitSwitch.h"
#include <util/delay.h> // For simple delays

int main(void) {
    // Configure PB0 as input for the button
    DDRB &= ~(1 << PB0); // Set PB0 as input

    // Configure PB4, PB5, PB6, and PB7 as outputs for LEDs
    DDRB |= (1 << PB4) | (1 << PB5) | (1 << PB6) | (1 << PB7);

    while (1) {
        // Get the press count
        uint16_t presses = countLimitSwitchPresses(PB0, &PORTB, &PINB);

        // Display the press count on LEDs in binary
        if (presses & (1 << 0)) { PORTB |= (1 << PB4); } else { PORTB &= ~(1 << PB4); } // PB4 = Bit 0
        if (presses & (1 << 1)) { PORTB |= (1 << PB5); } else { PORTB &= ~(1 << PB5); } // PB5 = Bit 1
        if (presses & (1 << 2)) { PORTB |= (1 << PB6); } else { PORTB &= ~(1 << PB6); } // PB6 = Bit 2
        if (presses & (1 << 3)) { PORTB |= (1 << PB7); } else { PORTB &= ~(1 << PB7); } // PB7 = Bit 3

        _delay_ms(10); // Small delay to stabilize
    }

    return 0;
}
