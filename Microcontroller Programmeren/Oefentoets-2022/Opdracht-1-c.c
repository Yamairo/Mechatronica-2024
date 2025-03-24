#include <avr/io.h>
#include <util/delay.h>

#define D1 PB7
#define D2 PB6
#define D3 PB5
#define D4 PB4

#define S1 PF1
#define S2 PF2
#define S3 PF3

void initc(void) {
    DDRB |= (1 << D1) | (1 << D4);
    PORTB &= ~(1 << D4);
}

void opdracht1c(void) {
    int ingedrukt = 0;
    while(!(PINF & (1 << S2))) {
        ingedrukt = 1;
    }
    if(ingedrukt) {
        PORTB ^= (1 << D4);
    }
}

