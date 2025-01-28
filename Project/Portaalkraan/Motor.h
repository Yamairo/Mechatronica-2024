#ifndef MOTOR_H
#define MOTOR_H

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

// Pin-definities voor motorbediening
#define LPWM PL5  // Pin 44: Links PWM (voor horizontale beweging)
#define RPWM PL3  // Pin 46: Rechts PWM (voor horizontale beweging)
#define LPWM2 PL4 // Pin 45: Links PWM2 (voor verticale beweging)
#define RPWM2 PL2 // Pin 47: Rechts PWM2 (voor verticale beweging)
#define vcc1 PA0    // Pin 22: Algemene uitgang
#define vcc2 PA1    // Pin 23: Algemene uitgang
#define uint_8t richting

// Functieprototypes

/**
 * @brief Initialiseer de timer (Timer0) voor PWM-controle.
 *        Dit omvat het instellen van de timer-modus, prescaler en interrupts
 *        die nodig zijn voor motorbediening.
 */
void init_timer(void);

/**
 * Functie om de timer (Timer0) uit te schakelen
 */
void stop_timer(void);

/**
 * @brief Configureer de benodigde pins voor motorbesturing.
 *        Stelt pin-modi in (input/output) en schakelt pull-up weerstanden in waar nodig.
 */
void init_pins(void);

/**
 * @brief Initialiseer zowel de timer als de pins.
 *        Zorgt ervoor dat de hardware correct is ingesteld voordat de motor wordt gebruikt.
 */
void init(void);

// Interrupt Service Routines (ISRs)

/**
 * @brief ISR voor Compare Match A van Timer0.
 *        Deze routine schakelt de actieve PWM-signalen uit (laag) wanneer een compare match plaatsvindt.
 */
ISR(TIMER0_COMPA_vect);

/**
 * @brief ISR voor Overflow van Timer0.
 *        Deze routine schakelt de actieve PWM-signalen in (hoog) bij een overflow van Timer0.
 */
ISR(TIMER0_OVF_vect);

/**
 * @brief Activeer PWM voor de LPWM-pin (Pin 44).
 *        Dit zorgt ervoor dat de motor naar links beweegt.
 */
void motorBeweegLinks(void);

/**
 * @brief Activeer PWM voor de LPWM-pin (Pin 47).
 *        Dit zorgt ervoor dat de motor naar links beweegt.
 */
void motorBeweegRechts(void);

/**
 * @brief Activeer PWM voor de RPWM-pin (Pin 46).
 *        Dit zorgt ervoor dat de motor naar beneden beweegt.
 */
void motorBeweegOmlaag(void);

/**
 * @brief Activeer PWM voor de LPWM2-pin (Pin 45).
 *        Dit zorgt ervoor dat de motor naar boven beweegt.
 */
void motorBeweegOmhoog(void);

/**
 * @brief Schakel alle motoruitgangen uit (LPWM, RPWM, LPWM2, RPWM2).
 *        Dit stopt alle bewegingen van de motor.
 */
void motorStop(void);

#endif // MOTOR_H
