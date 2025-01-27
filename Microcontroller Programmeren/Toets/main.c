#include <avr/io.h>

int main() {
    DDRB |= (1 << PB7);
    PORTB |= (1 << PB7);
    TCCR1A = 0;
    TCCR1B = (1 << CS12) | (0 << CS11) | (0 << CS10);
    TCNT1 = 34286;
    while(1) {
        if(TIFR1 &(1 << TOV1)) {
            TCNT1 = 34286;
            TIFR1 = (1 << TOV1);
            PORTB ^= (1 << PB7);
        }
    }
}
