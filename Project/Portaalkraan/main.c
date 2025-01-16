#include "Portaalkraan.h"
#include <avr/io.h>
#include <util/delay.h>

static uint16_t distanceCount = 0; // Tracks the distance traveled

int main(void) {
    initPortaalkraan(); // Initialize the system
    nulpuntPortaalkraan();
    while (1) {
        uint16_t distance = afstandPortaalkraan(); // Read distance
        motorBeweegRechts();
        if (distance == 10) {
            motorStop();
            pakPotplantOp();
            motorBeweegRechts();
        }
        if (distance == 30) {
            motorStop();
            zetPotplantNeer();
            nulpuntPortaalkraan();
            exit();
        }
    }

    return 0;
}
