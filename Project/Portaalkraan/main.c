#include "Portaalkraan.h"
#include <avr/io.h>
#include <util/delay.h>

static uint16_t distanceCount = 0; // Houdt de afgelegde afstand bij

int main(void) {
    initPortaalkraan(); // Initialiseer het systeem
    nulpuntPortaalkraan(); // Beweeg naar het nulpunt

    while (1) {
        uint16_t distance = afstandPortaalkraan(); // Lees de huidige afstand

        motorBeweegRechts(); // Beweeg de kraan naar rechts

        // Controleer of de afstand 10 eenheden is
        if (distance == 10) {
            motorStop();       // Stop de motor
            pakPotplantOp();   // Pak de potplant op
            motorBeweegRechts(); // Ga verder naar rechts
        }

        // Controleer of de afstand 30 eenheden is
        if (distance == 30) {
            motorStop();         // Stop de motor
            zetPotplantNeer();   // Zet de potplant neer
            nulpuntPortaalkraan(); // Keer terug naar het nulpunt
            exit();
        }
    }

    return 0; // Bereik dit nooit
}

