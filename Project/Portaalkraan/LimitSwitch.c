#include "LimitSwitch.h"
#include "Motor.h"


volatile uint8_t wasPressed = 0;
volatile int pressCount = 0;

// In motor.h
extern int rpwm_active;
extern int lpwm_active;



int isLimitSwitchPressed(uint8_t inputPin, volatile uint8_t *inputPort, volatile uint8_t *pinReg) {
    // Zet de inputport als pull-up resistor, dit wordt gedaan om een knop te gebruiken
    *inputPort |= (1 << inputPin);

    // Controleer of de knop is ingedrukt (active low)
    if (!(*pinReg & (1 << inputPin))) {
        // Als de knop is ingedrukt return 1
        return 1;
    } else {
        // Anders return 0
        return 0;
    }
}

/**
 * @brief Tel het aantal keren dat een limietschakelaar wordt geactiveerd,
 *        en pas de teller aan op basis van de bewegingsrichting.
 *
 * @param inputPin De pin van de limietschakelaar.
 * @param inputPort De poort waaraan de limietschakelaar is verbonden.
 * @param pinReg Het pinregister voor het lezen van de limietschakelaarstatus.
 * @param richting De bewegingsrichting: -1 voor links, +1 voor rechts.
 * @return De bijgewerkte waarde van de teller.
 */
uint16_t countLimitSwitchPresses(uint8_t inputPin, volatile uint8_t *inputPort, volatile uint8_t *pinReg) {
    // Houdt het aantal keer dat de switch is ingedrukt om bij te houden wat de huidige positie is
    static int16_t pressCount = 0;
    
    // Getal om bij te houden of de knop is ingedrukt
    static uint8_t wasPressed = 0;

    // Configureer de input pin met een pull-up weerstand
    *inputPort |= (1 << inputPin);

    // Controleer of de knop momenteel is ingedrukt
    if (!(*pinReg & (1 << inputPin))) {
        // Detecteer overgang van niet-ingedrukt naar ingedrukt
        if ((!wasPressed) & rpwm_active) {
            /*
            Als de knop ingedrukt wordt en de motor naar rechts draait,
            dan zal de teller met een omhoog gaan.
            */
            pressCount ++;
            wasPressed = 1;
            _delay_ms(50);
        } if ((!wasPressed) & lpwm_active) { 
            /*
            Als de knop ingedrukt wordt en de motor naar links draait,
            dan zal de teller met een omlaag gaan.
            */
            pressCount -= 1;
            wasPressed = 1;
            _delay_ms(50);
        }
    } else {
        // Reset de ingedrukte status
        wasPressed = 0;
    }

    if (pressCount < 0) {
        pressCount = 0;
    }

    // Geef de tellerwaarde terug als unsigned integer
    return pressCount;
}
