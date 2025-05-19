#include <avr/io.h>
#include <util/delay.h>

#define D1 PB7
#define D2 PB6
#define D3 PB5
#define D4 PB4

#define S1 PF1
#define S2 PF2
#define S3 PF3

void init_timerc(void) {
    TCCR1A |= 0;
    TCCR1B |= (1 << CS12);
    TCCR1C |= 0;

    TCNT1 |= 31250;
}

void init2c(void) {
    init_timerc;
    DDRB |= (1 << D1);
}

void opdracht2c(void) {
    if(TIFR1 & (1 << TOV1)) {
        TCNT1 = 31250;
        TIFR1 |= (1 << TOV1);
        PORTB ^= (1 << D1);
    }
}

