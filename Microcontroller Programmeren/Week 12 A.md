---
created: 2024-11-26T08:47
updated: 2024-11-26T10:15
---
# Inhoudsopgave
```toc
```

## Oefening segment display
*Geef het bitpatroon om een minteken te tonen op display 3*

Dit zorgt voor het min teken
`1111 1101`
En dit zet display 3 aan
`0010 0000`


## Timers
De AVR 2560 heeft vijf timers:
- 8 bit timers: timer 0 en 2
- 16 bit timers: timer 1, 3, 4 en 5

### Hardware 
Door middel van registers kan je vanuit de databus timers en andere hardware besturen.

### [[Timer Registers]] 
`TCNTx` Timer/Counter Register
`OCRx` Output Compare Register
`ICRx` Input Capture Register (alleen voor 16 bit timer)
`TIMSKx` Timer/Counter Interrupt Mask Register
`TIFRx` Timer/Counter Interrupt Flag Register

Voor onze [[Microcontroller]]  gebruiken we TCCRA, TCCRB, TCCRC

### Pre-scaler
De [[Microcontroller]] heeft een kloksnelheid van 16 MHz maar de timer is maximaal 16 bit groot dus dit zou ervoor zorgen dat je maar maximaal een interval van 6 ms zou kunnen hebben. Hiervoor gebruik je pre-scalers om te zorgen dat de kloksnelheid richting de timer langzamer wordt.

## Oefening timer
`Configureer de timer`
- Normal mode
- Ongeveer 1 kHz

WGM 0, WGM 1, WGM 2 moeten 0 worden

Dus dan heb je 
TCCRA `xxxx --00`
TCCRB `xx-- 0xxx`

---

$T = 1 ms =1 \cdot 10^{-3}s$

$f_{I/O} = 16MHz$
$T_\frac{I}{O}= \frac{1}{f} = \frac{1}{16 MHz} = 62 ns$

$\frac{1\cdot10^{-1}}{{62\cdot10^{-9}}}=16000$
Prescaler berekenen:
$\frac{16000}{256}=62.5\approx64$
CS = `0b011`

Dus dan heb je
TCCRA `0000 --00`
TCCRB `00-- 0011`

---

De – zijn reserved bits deze moeten 0 zijn 
Dus dan wordt het

TCCRA `0000 0000`
TCCRB `0000 0011`

---

## Timer code
Om te zien of de timer klaar is moet je in het TIFR kijken
```c
void initTImer(void)
{
	// Timer 0 is de systeemtimer (overflow)
	TCCR0A = 0;
	// TImer 8 kan niet ver genoeg tellen
	// 16MHz / 64 / 256 = 976.56Hz
	// start timer 0, prescaler 64
	TCCR0B = TCCR0b | (! << CS01) | (1 CS00)
}
```

```c
int teller = 0;
while(1)
{
	if(TIFR0 & (1 << TOV0))
	{
		// TImer overflow, +/- 1 ms voorbij
		FIFR = (1<<TOV0); // Wis flag
		if (teller++ >500)
		{
			
		}
	}
}
```

## Oefening 
- Zorg dat de timing precies goed is:
	- Je kan TCNT 0 ook een initiële waarde geven
	- Je kan ook een andere klokdeler instellen