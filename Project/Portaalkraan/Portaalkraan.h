#ifndef PORTAALKRAAN_H
#define PORTAALKRAAN_H

#include <stdint.h>

/**
*@brief Initialiseer alle pins zodat de portaalkraan volledig werkt.
*/
void initPortaalkraan(void);

/**
*@brief Beweeg naar links tot de limitswitch wordt geraakt,
*       zet dan het huidige coördinaat op 0.
*/
void nulpuntPortaalkraan(void);

/**
*@brief Tel het aantal keer dat de limitswitch, op de y-as,
*       wordt ingedrukt, dit wordt als int teruggegeven.
*       dit is ook gelijk het huidige y-coördinaat.7
*/
uint16_t afstandPortaalkraan(void);


void portaalkraanMagneet(void);

void pakPotplantOp(void);

#endif // PORTAALKRAAN_H
