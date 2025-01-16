#include "motor.h"

// Global variables to track motor state
volatile uint8_t lpwm_active = 0;
volatile uint8_t rpwm_active = 0;
volatile uint8_t lpwm2_active = 0;
volatile uint8_t rpwm2_active = 0;

void init_timer(void)
{
    // Set Normal mode, Pre-scaler = 64
    TCCR0A = 0;
    TCCR0B = (0 << CS02) | (1 << CS01) | (1 << CS00);
    OCR0A = 127;  // 50% duty cycle
    TIMSK0 = (1 << OCIE0A) | (1 << TOIE0); // Enable Compare A and Overflow interrupts
}

void init_pins(void)
{
    // Debug LED
    DDRB |= (1 << PB6);

    // Motor control pins (LPWM, RPWM) as output, initially off
    DDRL |= (1 << LPWM) | (1 << RPWM);
    PORTL &= ~(1 << LPWM) & ~(1 << RPWM);

    // Pin 22 as output
    DDRA |= (1 << v5);

    // Button on PF1 with pull-up
    DDRF &= ~(1 << PF1);  // Set PF1 as input
    PORTF |= (1 << PF1);  // Enable pull-up resistor
}

void init(void)
{
    init_pins();
    init_timer();
    sei(); // Enable global interrupts
}

void motorBeweegLinks(void)
{
    lpwm_active = 1;
    rpwm_active = 0;
}

void motorBeweegRechts(void)
{
    rpwm_active = 1;
    lpwm_active = 0;
}

void motorBeweegOmlaag(void)
{
    rpwm2_active = 1;
    lpwm2_active = 0;
}

void motorBeweegOmhoog(void)
{
    lpwm2_active = 1;
    rpwm2_active = 0;
}


void motorStop(void)
{
    lpwm_active = 0;
    rpwm_active = 0;

    PORTL &= ~(1 << LPWM) & ~(1 << RPWM) & ~(1 << LPWM2) & ~(1 << RPWM2); // Turn off all outputs
}

ISR(TIMER0_COMPA_vect)
{
    if (lpwm_active)
    {
        PORTL &= ~(1 << LPWM); // Turn off LPWM
    }
    if (rpwm_active)
    {
        PORTL &= ~(1 << RPWM); // Turn off RPWM
    }
    if (lpwm2_active)
    {
        PORTL &= ~(1 << LPWM2);
    }
    if (rpwm2_active)
    {
        PORTL &= ~(1 << RPWM2);
    }
}

ISR(TIMER0_OVF_vect)
{
    if (lpwm_active)
    {
        PORTL |= (1 << LPWM); // Turn on LPWM
    }
    if (rpwm_active)
    {
        PORTL |= (1 << RPWM); // Turn on RPWM
    }
    if (lpwm2_active)
    {
        PORTL |= (1 << LPWM2); // Turn on LPWM
    }
    if (rpwm2_active)
    {
        PORTL |= (1 << RPWM2); // Turn on RPWM
    }
}
