/*
 */

#include <avr/io.h>



int main(void)
{

    DDRB |= (1 << PB7);
    while(1) {
        if((PINC & (1 << PC2))) {
            PORTB ^= (1 << PB7);
        }
    }

    return 0;
}
