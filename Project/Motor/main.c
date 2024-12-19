/*
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

// Define motor control pins
#define LPWM PL5 // Pin 44 (OCR5H/L)
#define RPWM PL3 // Pin 46 (OCR5C)
#define v5 PA0   // Pin 22

// Enum for motor direction
typedef enum {
    MOTOR_STOP,
    MOTOR_FORWARD,
    MOTOR_BACKWARD
} MotorDirection;

// Initialize Timer5 for PWM
void init_timer(void)
{
    // Set Fast PWM mode, TOP = ICR5, non-inverting mode
    TCCR5A = (1 << COM5A1) | (1 << COM5C1) | (1 << WGM51);
    TCCR5B = (1 << WGM53) | (1 << WGM52) | (1 << CS51); // Prescaler = 8

    // Set TOP value for a 20ms period (50Hz for servos/motors, optional)
    ICR5 = 39999; // For 50Hz PWM with F_CPU = 16MHz and Prescaler = 8

    // Initialize duty cycles to 0
    OCR5A = 0; // LPWM (speed for forward)
    OCR5C = 0; // RPWM (speed for backward)
}

// Initialize pins
void init_pins(void)
{
    // Debugging LED
    DDRB |= (1 << PB6);

    // Set PWM pins (44 and 46) as output
    DDRL |= (1 << LPWM) | (1 << RPWM);

    // Set pin 22 as output
    DDRA |= (1 << v5);

    // Set button pin as pull-up
    DDRF &= ~(1 << PF1);
    PORTF |= (1 << PF1);
}

// Function to control motor direction and speed
void control_motor(MotorDirection direction, uint8_t speed_percent)
{
    // Map speed percentage (0-100%) to PWM duty cycle
    uint16_t duty_cycle = (ICR5 * speed_percent) / 100;

    switch (direction)
    {
        case MOTOR_STOP:
            OCR5A = 0; // Stop forward PWM
            OCR5C = 0; // Stop backward PWM
            break;

        case MOTOR_FORWARD:
            OCR5A = duty_cycle; // Set forward PWM
            OCR5C = 0;          // Stop backward PWM
            break;

        case MOTOR_BACKWARD:
            OCR5A = 0;          // Stop forward PWM
            OCR5C = duty_cycle; // Set backward PWM
            break;
    }
}

// Initialize the system
void init(void)
{
    init_pins();
    init_timer();
    sei(); // Enable global interrupts
}

int main(void)
{
    init();

    // Example: Control motor direction and speed in the main loop
    while (1)
    {
        control_motor(MOTOR_FORWARD, 50); // Move motor forward at 50% speed
        _delay_ms(2000);

        control_motor(MOTOR_STOP, 0);      // Stop motor

        control_motor(MOTOR_BACKWARD, 75); // Move motor backward at 75% speed
        _delay_ms(2000);

        control_motor(MOTOR_STOP, 0);      // Stop motor
        _delay_ms(1000);
    }

    return 0;
}
