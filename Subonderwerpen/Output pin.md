Datasheet hoofdstuk I/O-Ports: 
- DDRx register (Data Direction Register) bepaalt input/output.
- Een `1` op de juiste plaats maakt de corresponderende pin output.
- PORTx register bepaalt de waarde op de output. 
- Een `1` op de juiste plaats maakt de corresponderende pin hoog.
![[Pasted image 20230906125714.png

---

Voor de Mega: PB 7
	DDRB = `0b10000000`
	PORTB = `ob10000000`

In code zou dit er als volgt uitzien:
```c
#include <avr/io.h> // voor gebruik DDRx 
#include <util/delay.h> // voor delay_ms()
int main(void) 
{ 
	// configureer 
	pin DDRB = 0b10000000; 
	// voor de Mega 
	while (1) 
	{
		// Zet led aan 
		PORTB = 0b00000000;// aanzetten met '0' 
		// Wacht 500 ms 
		// Zet led uit 
		PORTB = 0b10000000; // uitzetten met '1' 
		// Wacht 500 ms 
	}
}
```