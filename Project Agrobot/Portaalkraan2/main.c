#include "Portaalkraan.h"
#include <avr/io.h>
#include <util/delay.h>

static uint16_t distanceCount = 0; // Houdt de afgelegde afstand bij

int main(void) {
    initPortaalkraan(); // Initialiseer het systeem
    nulpuntPortaalkraan(); // Beweeg naar het nulpunt

    while (1) {
        int eindpunt = kiesCoordinaat();
        uint16_t distance = afstandPortaalkraan(); // Lees de huidige afstand

        motorBeweegRechts(); // Beweeg de kraan naar rechts

        // Controleer of de afstand 10 eenheden is
        if (distance == eindpunt) {
            motorStop();       // Stop de motor
            pakPotplantOp();   // Pak de potplant op
        }
    }

    return 0; // Bereik dit nooit
}

