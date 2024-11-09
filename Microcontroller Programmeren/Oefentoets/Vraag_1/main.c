#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // Zet leds 1, 2, 3, 4 als output
    DDRB |= (1 << PB4) | (1 << PB5) | (1 << PB6) | (1 << PB7);

    // Zet led 2 uit
    PORTB |= (1 << PB6);

    // Zet knop 1 en 2 als input
    PORTF |= (1 << PF1) | (1 << PF2);

    while (1)
    {
        // Zet led 3 en 4 aan
        PORTB &= ~((1 << PB4) | (1 << PB5));
        if (!(PINF & (1 << PF1))) // Als knop 1 wordt ingedrukt
        {
            PORTB &= ~(1 << PB7); // Zet led 1 aan
        }
        else if(!(PINF & (1 << PF2))) // Als knop 2 wordt ingedrukt
        {
            PORTB &= ~(1 << PB6); // Zet led 2 aan
        }
        else // Als knop 1 en 2 niet ingedrukt zijn
        {
            PORTB |= (1 << PB7); // Zet led 1 uit
        }

        // Delay voor debounce
        _delay_ms(50);
    }

    return 0;
}
