---
created: 2024-12-19T13:49
updated: 2024-12-19T13:51
---
Met deze code kan je de lpwm en rpwm aanzetten dit leid tot het draaien van de motor
```c
/*
De bedrading van de H-brug en arduino is alsvolgt
H-brug -> arduino
Vcc -> pin 22
Gnd -> Gnd
L_en -> Vcc
R_en -> Vcc
RPWM -> pin 44
LPWM -> pin 46
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define LPWM PL5 // 44
#define RPWM PL3 // 46
#define v5 PA0 // 22

void init_timer(void)
{
    // Mode 0, Pre-scaler = 64
    TCCR0A = 0;
    TCCR0B = (0 << CS02) | (1 << CS01) | (1 << CS00);

    // 5-% duty cycle (0 - 255) = (0% - 100%)
    OCR0A = 127;

    // Interrupt op OCA en OVF
    TIMSK0 = (1 << OCIE0A) | (1 << TOIE0);
}

void init_pins(void)
{
    // Lampjes voor test
    DDRB |= (1 << PB6);

    // Zet de PWM pins 44 en 46 als output en zet ze uit
    DDRL |= (1 << LPWM) | (1 << RPWM);
    PORTL &= ~(1 << LPWM) & ~(1 << RPWM);

    // Zet pin 22 als output
    DDRA |= (1 << v5);

    // Zet de pins van knop 1 als pull-up
    DDRF |= (1 << PF1);
    PORTF |= (1 << PF1);
}

void init(void)
{
    init_pins();
    init_timer();
    sei();
}

ISR(TIMER0_COMPA_vect)
{
    PORTL &= ~(1 << RPWM);
    DDRB &= ~(1 << PB6);
}

ISR(TIMER0_OVF_vect)
{
    PORTL |= (1 << RPWM);
    DDRB |= (1 << PB6);
}

int main(void)
{
    init();
    while(1)
    {

    }
    return 0;
}

```