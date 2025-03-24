#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define D1 PB7
#define D2 PB6
#define D3 PB5
#define D4 PB4

#define S1 PF1
#define S2 PF2
#define S3 PF3

void init_timerb(void) {
    TCCR1A |= 0;
    TCCR1B |= (1 << CS12) | (0<<CS11) | (0<<CS10);
    TCCR1C |= 0;

    TCNT1 = 56636 - 208333;
    OCR1A = TCNT1 + 6250;

    TIMSK1 |= (1 << OCIE1A) | (1 <<TOIE1);
}

void init2b(void) {
    init_timerb();
    DDRB |= (1 << D1);
    sei();
}

ISR(TIMER1_COMPA_vect) {
    PORTB &= ~(1 << D1);
}

ISR(TIMER1_OVF_vect) {
    TCNT1 = 56636 - 208333;
    PORTB |= (1 << D1);
}

void opdracht2b(void) {
    init2b();
    while(1) {

    }
}


