#include "Portaalkraan.h"
#include <avr/io.h>
#include <util/delay.h>

static uint16_t distanceCount = 0; // Tracks the distance traveled

int main(void) {
    initPortaalkraan(); // Initialize the system
    nulpuntPortaalkraan();
    while (1) {
        uint16_t distance = afstandPortaalkraan(); // Read distance
        portaalkraanMagneet();               // Check magnet safety
        motorBeweegRechts();
        // Optional: Use distance for further control
        if (distance > 10) {
            motorStop();
        }
    }

    return 0;
}
