#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // Zet leds 1, 2, 3, 4 als output (PB4, PB5, PB6, PB7)
    DDRB |= (1 << PB4) | (1 << PB5) | (1 << PB6) | (1 << PB7);

    // Zet leds 3, 4 uit (PB4, PB5) initieel
    PORTB |= (1 << PB4) | (1 << PB5);

    // Zet knop 3 als input (PF3)
    DDRF &= ~(1 << PF3);  // PF3 als input instellen
    PORTF |= (1 << PF3);  // Interne pull-up weerstand activeren op PF3

    // Zet teller op 0
    int teller = 0;

    while(1)
    {
        // Controleer of de knop is ingedrukt (knop op PF3, active-low)
        if (!(PINF & (1 << PF3)))
        {
            // Wacht tot de knop wordt losgelaten
            _delay_ms(50);  // Debounce vertraging
            while (!(PINF & (1 << PF3)));  // Wacht tot knop is losgelaten

            // Verhoog teller na elke druk
            teller++;
        }

        // Zet de led aan na twee keer drukken
        if (teller == 2)
        {
            PORTB &= ~(1 << PB4);  // Zet LED op PB4 aan
        }

        _delay_ms(50);  // Extra debounce vertraging indien nodig
    }

    return 0;
}
