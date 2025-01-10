#include "Portaalkraan.h"
#include <util/delay.h>

int main(void) {
    initPortaalkraan(); // Initialize the system

    nulpuntPortaalkraan(); // Find the zero point

    while (1) {
        uint16_t distance = afstandPortaalkraan(); // Read distance
        portaalkraanMagneet();               // Check magnet safety

        // Optional: Use distance for further control
        if (distance > 10) {
            // Perform some action based on distance
        }

        _delay_ms(100); // Main loop delay
    }

    return 0;
}
