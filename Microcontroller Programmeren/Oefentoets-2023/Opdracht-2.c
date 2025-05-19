#include <avr/io.h>

#define D1 PB7
#define D2 PB6
#define D3 PB5
#define D4 PB4

#define S1 PF1
#define S2 PF2
#define S3 PF3

void init2(void) {
    DDRB |= (1 << D1) | (1 << D4);
    PORTB |= (1 << D1);
}

void opdracht2(void) {
    if(!(PINF & (1 << S3))) {
        PORTB &= ~(1 << D1);
    }
}
