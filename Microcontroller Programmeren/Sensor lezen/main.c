// Quick Demo of internal potentiometer on ATmega2560
#include <avr/io.h>
#include <util/delay.h>

// Initialize ADC for the internal potentiometer
static inline void initADC0(void) {
    ADMUX |= (1 << REFS0); /* Use AVCC as reference voltage */
    ADMUX |= (1 << MUX2) | (1 << MUX1) | (1 << MUX0); /* Select ADC7 (internal potentiometer) */
    ADCSRA |= (1 << ADPS1) | (1 << ADPS0); /* ADC clock prescaler /8 */
    ADCSRA |= (1 << ADEN); /* Enable ADC */
}

int main(void) {
    uint8_t ledValue;
    uint16_t adcValue;
    uint8_t i;

    initADC0();
    DDRD = 0xff; // Configure PORTD as output for LEDs

    while (1) {
        ADCSRA |= (1 << ADSC); /* Start ADC conversion */
        loop_until_bit_is_clear(ADCSRA, ADSC); /* Wait until done */
        adcValue = ADC; /* Read ADC value */

        /* Map ADC value (0–1023) to 3 bits (0–7) for 8 LEDs */
        ledValue = (adcValue >> 7);

        /* Light up LEDs based on the mapped value */
        PORTD = 0; // Clear all LEDs
        for (i = 0; i <= ledValue; i++) {
            PORTD |= (1 << i); // Turn on LED i
        }

        _delay_ms(50); // Short delay for visibility
    }

    return 0;
}
