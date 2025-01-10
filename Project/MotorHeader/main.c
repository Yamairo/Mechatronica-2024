#include "Motor.h"
int main(void)
{
    int time = 5000;
    int wait = 100;
    init(); // Initialize motor control system
    while (1)
    {
        motorBeweegLinks(); // Enable LPWM with PWM
        _delay_ms(time); // Run for 1 second
        motorStop(); // Disable both
        _delay_ms(wait); // Pause for 1 second
        motorBeweegRechts(); // Enable RPWM with PWM
        _delay_ms(time); // Run for 1 second
        motorStop(); // Disable both
        _delay_ms(wait); // Pause for 1 second
    }
    return 0;
}
