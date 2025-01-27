#ifndef PORTAALKRAAN_H
#define PORTAALKRAAN_H

#include <stdint.h>

/**
 * @brief Initialiseer alle pins zodat de portaalkraan volledig werkt.
 *        Dit omvat het instellen van de juiste pin-modi en het activeren
 *        van eventuele pull-up weerstanden.
 */
void initPortaalkraan(void);

/**
 * @brief Beweeg naar links tot de limietschakelaar wordt geactiveerd
 *        en stel het huidige coördinaat op 0 in.
 *        Dit nulpunt dient als referentiepunt voor verdere bewegingen.
 */
void nulpuntPortaalkraan(void);

/**
 * @brief Tel het aantal keren dat de limietschakelaar op de y-as wordt geactiveerd.
 *        Dit aantal wordt teruggegeven als een geheel getal (uint16_t)
 *        en stelt het huidige y-coördinaat van de portaalkraan voor.
 *
 * @return Het huidige y-coördinaat (aantal activeringen van de limietschakelaar).
 */
uint16_t afstandPortaalkraan();

/**
 * @brief Schakel de magneet van de portaalkraan in om objecten vast te houden.
 *        Dit kan bijvoorbeeld worden gebruikt om een potplant op te pakken.
 */
void portaalkraanMagneetAan(void);

/**
 * @brief Schakel de magneet van de portaalkraan uit om objecten los te laten.
 */
void portaalkraanMagneetUit(void);

/**
 * @brief Pak een potplant op door de kraan naar beneden te bewegen
 *        totdat de limietschakelaar wordt geactiveerd, terwijl de magneet wordt ingeschakeld.
 */
void pakPotplantOp(void);

/**
 * @brief Zet een potplant neer door de kraan naar beneden te bewegen
 *        totdat de limietschakelaar wordt geactiveerd, daarna wordt de magneet uitgeschakeld.
 */
void zetPotplantNeer(void)
#endif // PORTAALKRAAN_H
