#include <avr/io.h>

#define D1 PB7
#define D2 PB6
#define D3 PB5
#define D4 PB4
#define S1 PF1
#define S2 PF2
#define S3 PF3

void initB(){
    DDRB |= (1 << D1) | (1 << D2);
}

void opdrachtB(void) {
    if(!(PINF & (1 << S2))) {
        PORTB |= (1 << D2);
    }
}
