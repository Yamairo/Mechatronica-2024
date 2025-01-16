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

