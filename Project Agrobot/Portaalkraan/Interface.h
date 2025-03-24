#ifndef INTERFACE_H
#define INTERFACE_H

#include <avr/io.h>
#include <util/delay.h>

/*
Definieer S1, S2 en S3 als PF1, PF2 en PF3
Definieer de benodigde bits en ports voor het sturen van de data naar het display
Deze definities kunnen worden gebruikt in alle bestanden met "Interface.h"
*/

#define S1 PF1
#define S2 PF2
#define S3 PF3

#define SDI_BIT		PH5
#define DDR_SDI		DDRH
#define PORT_SDI	PORTH

#define SFTCLK_BIT	PH4
#define DDR_SFTCLK	DDRH
#define PORT_SFTCLK	PORTH

#define LCHCLK_BIT	PG5
#define DDR_LCHCLK	DDRG
#define PORT_LCHCLK	PORTG

#define DEBOUNCE_DELAY 50

/*
Definieer de functies benodigd voor het aandrijven van het segmentdisplay,
en het kiezen van het coordinaat dat wordt getoond op het segmentdisplay.
*/

void init_interface(void);
void send_data(char data);
void send_enable(int display_nummer);
void display(char data, int display_nummer);
void display_getal(unsigned int getal);
int kiesCoordinaat(void);
#endif // INTERFACE_H
