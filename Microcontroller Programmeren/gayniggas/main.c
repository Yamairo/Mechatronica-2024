#include <avr/io.h>

// Led D1 = 13 = PB7
// Led D2 = 12 = PB6
// Led D3 = 11 = PB5
// Led D4 = 10 = PB4
// Knop S1 = A1 = PF1
// Knop S2 = A2 = PF2
// Knop S3 = A3 = PF3

// f = 1 Hz, timer should time 0.5 s
// 0.5 / (1/16 MHz) = 8000000 cycles
// Using prescaler of 256: 8000000 / 256 = 31250
// Init TCNT to 2^16 - 31250 = 34286
#define TCNT_INIT 34286

void init_led(void)
{
	DDRB |= (1<<PB7);
	PORTB |= (1<<PB7);
}

void init_timer1(void)
{
	TCCR1A = 0;
	TCCR1B = (1<<CS12) | (0<<CS11) | (0<<CS10);
	TCNT1 = TCNT_INIT;
}

void init(void)
{
	init_led();
	init_timer1();
}

void led_D1_on(void)
{
	PORTB &= ~(1<<PB7);
}

void led_D1_off(void)
{
	PORTB |= (1<<PB7);
}

void led_D1_toggle(void)
{
	PORTB ^= (1<<PB7);
}

int main(void)
{
	init();

	while (1)
	{
		if (TIFR1 & (1<<TOV1))
		{
			// Re-init tcnt
			TCNT1 = TCNT_INIT;
			// Clear flag
			TIFR1 = (1<<TOV1);
			// Toggle led D1
			led_D1_toggle();
		}
	}
}
