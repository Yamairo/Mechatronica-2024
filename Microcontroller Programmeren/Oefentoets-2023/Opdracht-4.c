#include <avr/io.h>
#include <avr/interrupt.h>

#define D1 PB7
#define D2 PB6
#define D3 PB5
#define D4 PB4

#define S1 PF1
#define S2 PF2
#define S3 PF3

#define TCNT_INIT 18461

/**
Schrijf een programma dat gebruik maakt van timer 4 om via polling led D3 te laten
knipperen. De periodetijd moet 1.5 s bedragen.
*/

void init4 (void) {
    initLed1();
    initTimer1();
}

void initLed1(void) {
    DDRB |= (1 << D3);
}

void initTimer1(void) {
    TCCR4A = 0;
    TCCR4B = (1 << CS42) | (0 << CS41) | (0 >> CS40);
    TCCR4C = 0;

    TCNT4 = TCNT_INIT;
}

void opdracht4(void) {
    if(TIFR4 & (1 << TOV4)) {
        PORTB ^= (1 << D3);
        TIFR4 |= (1 >> TOV4);
        TCNT4 = TCNT_INIT;
    }
}
