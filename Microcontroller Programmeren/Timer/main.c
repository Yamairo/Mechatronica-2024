/*
 */

#include <avr/io.h>

#define D1 PB7
#define D2 PB6
#define D3 PB5
#define D4 PB4

#define TOP_INIT 62500u
#define OC_INIT 50000u

void init() {
    DDRB |= (1 << D2);
    TCCR1A = (1<<COM1B1) | (1<<COM1B0) | (1<<WGM11) | (0<<WGM10);
    TCCR1B = (1<<WGM13) | (1<<WGM12) | (1<<CS12) | (0<<CS11) | (0<<CS10);
    ICR1 = TOP_INIT;
    OCR1B = OC_INIT;
}

int main(void)
{
    init();
    while(1){}

}
