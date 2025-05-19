#include "Portaalkraan.h"
#include "Interface.h"
#include "Noodknop.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int wacht = 1;

int main(void) {
    // Stap 1: Initialiseer de interface en toon het display
    init_interface();        // Initialiseer de interface (display en knoppen)
    while(1)
    {
        while (1) {  // Terwijl de noodknop ingedrukt is, voer de taak uit
            // Stap 2: Kies het eerste coördinaat en toon het op het display
            int punt_1 = kiesCoordinaat(); // Kies het eerste punt
            display_getal(punt_1);          // Toon het gekozen punt op het display
            _delay_ms(500);                 // Wacht even om het display te updaten

            // Stap 3: Kies het tweede coördinaat en toon het op het display
            int punt_2 = kiesCoordinaat(); // Kies het tweede punt
            display_getal(punt_2);          // Toon het gekozen punt op het display
            _delay_ms(500);                 // Wacht even om het display te updaten

            // Stap 4: Initialiseer de motor pas nu na de coördinatenkeuze
            initPortaalkraan();        // Initialiseer de motoren en sensoren
            nulpuntPortaalkraan();     // Beweeg naar het nulpunt van de kraan

            // Stap 5: Start de motorbeweging naar het eerste punt
            motorBeweegRechts();      // Begin met bewegen naar rechts naar punt_1
            uint16_t distance = afstandPortaalkraan();  // Lees de huidige afstand
            while ((distance != punt_1)) {
                distance = afstandPortaalkraan();  // Blijf de afstand controleren
                _delay_ms(wacht);  // Wacht een moment voor de volgende meting
                display_getal(punt_1); // Toon punt_1 op het display (continu bijwerken)
            }

            motorStop();  // Stop de motor als het eerste punt is bereikt
            pakPotplantOp();  // Pak de potplant op (bij punt_1)

            // Stap 6: Beweeg naar het tweede punt en zet de potplant neer
            motorBeweegRechts(); // Begin met bewegen naar rechts naar punt_2
            distance = afstandPortaalkraan();  // Lees de huidige afstand
            while ((distance != punt_2)) {
                distance = afstandPortaalkraan();  // Blijf de afstand controleren
                _delay_ms(wacht);  // Wacht een moment voor de volgende meting
                display_getal(punt_2); // Toon punt_2 op het display (continu bijwerken)
            }

            motorStop();  // Stop de motor als het tweede punt is bereikt
            pakPotplantOp();  // Zet de potplant neer (bij punt_2)

            _delay_ms(1000);  // Wacht even voordat je opnieuw begint
        }
    }


    return 0;
}
