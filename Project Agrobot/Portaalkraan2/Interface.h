#ifndef INTERFACE_H
#define INTERFACE_H

#include <avr/io.h>
#include <util/delay.h>

// Aansluitingen:
// 8: SDI	-> PH5
// 7: SFTCLK	-> PH4
// 4: LCHCLK	-> PG5
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

#define DEBOUNCE_DELAY 50 // 50 ms debounce delay

void init(void);
void send_data(char data);
void send_enable(int display_nummer);
void display(char data, int display_nummer);
void display_getal(unsigned int getal);
int kiesCoordinaat(void);

#endif // INTERFACE_H
