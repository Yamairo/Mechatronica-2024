#include "Portaalkraan.h"
#include <avr/io.h>
#include <util/delay.h>

static uint16_t distanceCount = 0; // Houdt de afgelegde afstand bij
int wacht = 1;
extern opgepakt;
extern volatile int pressCount;


int main(void) {
    // Stap 1: Initialiseer de interface en toon het display
    init_interface(); // Initialiseer de interface (display en knoppen)

    while (1) {
        while (1) {  // Terwijl de noodknop ingedrukt is, voer de taak uit
            int punt_1 = 11;
            display_getal(punt_1);
            _delay_ms(500);

            int punt_2 = 21;
            display_getal(punt_2);
            _delay_ms(500);

            initPortaalkraan();
            nulpuntPortaalkraan();

            // Reset de teller NA het nulpunt
            pressCount = 0;

            motorBeweegLinks();
            uint16_t distance = afstandPortaalkraan();
            while ((distance != punt_1) & !(opgepakt)) {
                distance = afstandPortaalkraan();
                _delay_ms(wacht);
                display_getal(punt_1);
            }

            motorStop();
            pakPotplantOp();

            // Controleer in welke richting de kraan moet bewegen
            if (punt_1 < punt_2) {
                motorBeweegLinks();  // Correctie: beweeg naar rechts
            } else {
                motorBeweegRechts();
            }

            distance = afstandPortaalkraan();
            while ((distance != punt_2)) {
                distance = afstandPortaalkraan();
                _delay_ms(wacht);
                display_getal(punt_2);
            }

            motorStop();
            zetPotplantNeer();

            nulpuntPortaalkraan();
            _delay_ms(1000);
            break;
        }
        break;
    }
}

