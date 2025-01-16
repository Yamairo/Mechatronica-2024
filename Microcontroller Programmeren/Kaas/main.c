/*
 */

#include <avr/io.h>
#include <util/delay.h>



int main(void) {
    // Configureer pin
    DDRB = 0b11000000; // voor de Mega
    while (1)
    {
        // Zet led aan
        PORTB = 0b00000000; // aanzetten met '0'
        // Wacht 500 ms
        _delay_ms(500);
        // Zet led uit
        PORTB = 0b11000000; // uitzetten met '1'
        // Wacht 500 ms
        _delay_ms(500);
    }
}
