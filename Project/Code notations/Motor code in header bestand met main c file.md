---
created: 2024-12-19T14:19
updated: 2025-01-17T00:30
---
# Inhoudsopgave
```toc
```


## Motor.c
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
#include "Motor.h"

#define LPWM PL5 // 44
#define RPWM PL3 // 46
#define v5 PA0 // 22

// Globale variabele om te kijken of lpwm of rpwm aan staat.
volatile uint8_t lpwm_active = 0;
volatile uint8_t rpwm_active = 0;

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

void enable_lpwm(void)
{
    lpwm_active = 1;
    rpwm_active = 0;
}

void enable_rpwm(void)
{
    rpwm_active = 1;
    lpwm_active = 0;
}

void disable_pwm(void)
{
    lpwm_active = 0;
    rpwm_active = 0;
    PORTL &= ~(1 << LPWM) & ~(1 << RPWM); // Zet LWPM en RPWM uit
}

ISR(TIMER0_COMPA_vect)
{
    if (lpwm_active)
    {
        PORTL &= ~(1 << LPWM); // Zet LPWM uit
    }

    if (rpwm_active)
    {
        PORTL &= ~(1 << RPWM); // Zet RPWM uit
    }

    DDRB &= ~(1 << PB6); // Update test output
}

ISR(TIMER0_OVF_vect)
{
    if (lpwm_active)
    {
        PORTL |= (1 << LPWM); // Zet LPWM aan
    }

    if (rpwm_active)
    {
        PORTL |= (1 << RPWM); // Zet RPWM aan
    }

    DDRB |= (1 << PB6); // Update test output
}


```

## Motor.h

```c
#ifndef MOTOR_H
#define MOTOR_H

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

// Pin Definitions
#define LPWM PL5 // Pin 44
#define RPWM PL3 // Pin 46
#define V5   PA0 // Pin 22

// Function Prototypes
/**
 * @brief Initialiseerd de timer voor PWM controle.
 */
void init_timer(void);

/**
 * @brief Configureer de pins voor motor besturing en controle.
 */
void init_pins(void);

/**
 * @brief Initialiseerd de timer en de pins.
 */
void init(void);

// Interrupt Service Routines (ISRs)
/**
 * @brief ISR voor Compare match A.
 */
ISR(TIMER0_COMPA_vect);

/**
 * @brief ISR voor TIMER0 Overflow.
 */
ISR(TIMER0_OVF_vect);

/**
 * @brief Enables PWM for LPWM (Pin 44).
 */
void enable_lpwm(void);

/**
 * @brief Enables PWM for RPWM (Pin 46).
 */
void enable_rpwm(void);

/**
 * @brief Disables both LPWM and RPWM outputs.
 */
void disable_pwm(void);

#endif // MOTOR_H
```

## Main.c

```c
#include "Motor.h"

int main(void)
{
    init(); // Initialize motor control system

    while (1)
    {
        enable_lpwm(); // Enable LPWM with PWM
        _delay_ms(1000); // Run for 1 second

        enable_rpwm(); // Enable RPWM with PWM
        _delay_ms(1000); // Run for 1 second

        disable_pwm(); // Disable both
        _delay_ms(1000); // Pause for 1 second
    }
    return 0;
}
```
