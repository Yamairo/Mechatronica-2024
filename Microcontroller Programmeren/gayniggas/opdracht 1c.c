#include <avr/io.h>
#include<util/delay.h>

#define D1 PB7
#define D2 PB6
#define D3 PB5
#define D4 PB4
#define S1 PF1
#define S2 PF2
#define S3 PF3

volatile int knopIngedrukt = 0;

void initC(){
    DDRB |= (1 << D1) | (1 << D4);

    PORTB |= (1 << D4);
}

void opdrachtC(void) {
    if(!(PINF & (1 << S2))) {
        if(!knopIngedrukt) {
            PORTB ^= (1 << D4);
            _delay_ms(20);
            knopIngedrukt = 1;
        }
    } else {
        if(knopIngedrukt) {
            knopIngedrukt = 0;
            _delay_ms(20);
        }
    }
}
