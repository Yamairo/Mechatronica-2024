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
uint16_t countLimitSwitchPresses(uint8_t inputPin, volatile uint8_t *inputPort, volatile uint8_t *pinReg, int8_t richting) {
    static int16_t pressCount = 0; // Persistent teller van activaties (kan negatief worden)
    static uint8_t wasPressed = 0; // Houdt de vorige status van de knop bij

    // Configureer de input pin met een pull-up weerstand
    *inputPort |= (1 << inputPin); // Schakel pull-up weerstand in

    // Controleer of de knop momenteel is ingedrukt
    if (!(*pinReg & (1 << inputPin))) { // Knop is ingedrukt
        if (!wasPressed) { // Detecteer overgang van niet-ingedrukt naar ingedrukt
            pressCount += richting; // Pas de teller aan op basis van de richting
            wasPressed = 1;         // Markeer de knop als ingedrukt
            _delay_ms(50);          // Simpele debounce-vertraging
        }
    } else { // Knop is niet ingedrukt
        wasPressed = 0; // Reset de ingedrukte status
    }

    // Zorg ervoor dat de teller niet negatief wordt als je dat wilt vermijden
    if (pressCount < 0) {
        pressCount = 0;
    }

    return (uint16_t)pressCount; // Geef de tellerwaarde terug als unsigned integer
}