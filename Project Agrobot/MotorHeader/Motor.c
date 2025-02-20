/*
De bedrading van de H-brug en arduino is alsvolgt
H-brug -> arduino
Vcc -> pin 22
Gnd -> Gnd
L_en -> Vcc
R_en -> Vcc
RPWM -> pin 44
LPWM -> pin 46
*/
#include "Motor.h"

#define LPWM PL5 // 44
#define RPWM PL3 // 46
#define v5 PA0 // 22

// Globale variabele om te kijken of lpwm of rpwm aan staat.
volatile uint8_t lpwm_active = 0;
volatile uint8_t rpwm_active = 0;

void init_timer(void)
{
  // Mode 0, Pre-scaler = 64
  TCCR0A = 0;
  TCCR0B = (0 << CS02) | (1 << CS01) | (1 << CS00);
  // 5-% duty cycle (0 - 255) = (0% - 100%)
  OCR0A = 127;
  // Interrupt op OCA en OVF
  TIMSK0 = (1 << OCIE0A) | (1 << TOIE0);
}

void init_pins(void)
{
  // Lampjes voor test
  DDRB |= (1 << PB6);
  // Zet de PWM pins 44 en 46 als output en zet ze uit
  DDRL |= (1 << LPWM) | (1 << RPWM);
  PORTL &= ~(1 << LPWM) & ~(1 << RPWM);
  // Zet pin 22 als output
  DDRA |= (1 << v5);
  // Zet de pins van knop 1 als pull-up
  DDRF |= (1 << PF1);
  PORTF |= (1 << PF1);
}

void init(void)
{
  init_pins();
  init_timer();
  sei();
}

void motorBeweegLinks(void)
{
  lpwm_active = 1;
  rpwm_active = 0;
}

void motorBeweegRechts(void)
{
  rpwm_active = 1;
  lpwm_active = 0;
}

void motorStop(void)
{
  lpwm_active = 0;
  rpwm_active = 0;
  PORTL &= ~(1 << LPWM) & ~(1 << RPWM); // Zet LWPM en RPWM uit
}

ISR(TIMER0_COMPA_vect)
{
  if (lpwm_active)
  {
    PORTL &= ~(1 << LPWM); // Zet LPWM uit
  }
  if (rpwm_active)
  {
    PORTL &= ~(1 << RPWM); // Zet RPWM uit
  }
  DDRB &= ~(1 << PB6); // Update test output
}

ISR(TIMER0_OVF_vect)
{
  if (lpwm_active)
  {
    PORTL |= (1 << LPWM); // Zet LPWM aan
  }
  if (rpwm_active)
  {
    PORTL |= (1 << RPWM); // Zet RPWM aan
  }
  DDRB |= (1 << PB6); // Update test output
}
