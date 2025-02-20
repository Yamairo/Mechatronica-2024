#ifndef F_CPU
#define F_CPU 16000000
#endif

#include "Interface.h"
#include "Noodknop.h"

int coordinaat = 0;
int tijd = 1;

static unsigned int segmentcodes[] = {
	~0xFC, ~0x60, ~0xDA, ~0xF2,
	~0x66, ~0xB6, ~0xBE, ~0xE0,
	~0xFE, ~0xF6, ~0xEE, ~0x3E,
	~0x9C, ~0x7A, ~0x9E, ~0x8E };

void init (void)
{
	// Initialiseer de pinnen voor datain, shiftclk en latchclk als output
	DDR_SDI    |= (1 << SDI_BIT);
	DDR_SFTCLK |= (1 << SFTCLK_BIT);
	DDR_LCHCLK |= (1 << LCHCLK_BIT);

	// Maak shiftclk en latchclk laag
	PORT_SFTCLK &= ~(1 << SFTCLK_BIT);
	PORT_LCHCLK &= ~(1 << LCHCLK_BIT);
}

void send_data(char data)
{
	for (unsigned i = 0; i < 8; i++)
	// Herhaal voor alle bits in een char
	{
		// Bepaal de waarde van de bit die je naar het schuifregister
		// wil sturen
		int bit = data & 1;
		data >>= 1;

		// Maak de juiste pin hoog of laag op basis van de bepaalde waarde
		// van het bit
		if (bit)
		{
			PORT_SDI |= (1 << SDI_BIT);
		}
		else
		{
			PORT_SDI &= ~(1 << SDI_BIT);
		}

		// Toggle shiftclk (hoeveel tijd moest het signaal minimaal hoog zijn?)
		// Puls moet minimaal 13 ns hoog zijn. Een clk cycle op de Arduino duurt
		// 62 ns, dus signaal kan hoog en de volgende cycle weer omlaag
		PORT_SFTCLK |= (1 << SFTCLK_BIT);
		PORT_SFTCLK &= ~(1 << SFTCLK_BIT);
	}
}

void send_enable(int display_nummer)
{
	send_data(0x10 << display_nummer);
}

void display(char data, int display_nummer)
{
	send_data(data);
	send_enable(display_nummer);

	// Toggle latchclk (hoeveel tijd moest het signaal minimaal hoog zijn?)
	// Puls moet minimaal 13 ns hoog zijn. Een clk cycle op de Arduino duurt
	// 62 ns, dus signaal kan hoog en de volgende cycle weer omlaag
	PORT_LCHCLK |= (1 << LCHCLK_BIT);
	PORT_LCHCLK &= ~(1 << LCHCLK_BIT);
}

void display_getal(unsigned int getal)
{
	for (int i = 0; i < 4; i++)
	{
		display(segmentcodes[getal%10], i);
		getal /= 10;
		_delay_ms(1);   // 1 kHz
	}
}

int kiesCoordinaat(void)
{
    while (!(isNoodkopIngedrukt())) // Loop until S3 is pressed
    {
        // Check button S1 for decrement
        if (!(PINF & (1 << S1)) && (coordinaat > 0)) {
            coordinaat--; // Decrement coordinaat
            while (!(PINF & (1 << S1))) {
                _delay_ms(tijd);
                display_getal(coordinaat);
            }
        }

        // Check button S2 for increment
        if (!(PINF & (1 << S2)) && (coordinaat < 100)) {
            coordinaat++; // Increment coordinaat
            while (!(PINF & (1 << S2))) {
                _delay_ms(tijd);
                display_getal(coordinaat);
            }
        }

        // Continuously display the current value of coordinaat
        display_getal(coordinaat);

        // Check button S3 for return
        if (!(PINF & (1 << S3))) {
            display_getal(0x0000); // Clear the display
            int result = coordinaat; // Store the current value
            coordinaat = 0;         // Reset coordinaat to zero
            return result;          // Return the stored value
        }
    }
}



