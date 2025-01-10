#ifndef PORTAALKRAAN_H
#define PORTAALKRAAN_H

#include <stdint.h>

// Initialize the Portaalkraan system
void initPortaalkraan(void);

// Move motor to zero point (stops when the zero-point limit switch is triggered)
void nulpuntPortaalkraan(void);

// Count distance based on limit switch triggers
uint16_t afstandPortaalkraan(void);

// Stop the magnet if the safety limit switch is triggered
void portaalkraanMagneet(void);

#endif // PORTAALKRAAN_H
