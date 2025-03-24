#include "Motor.h"
#include "Interface.h"

// Globale variabelen om de motorstatus bij te houden
volatile uint8_t lpwm_active = 0;  // Links PWM actief
volatile uint8_t rpwm_active = 0;  // Rechts PWM actief
volatile uint8_t lpwm2_active = 0; // Links PWM2 actief (voor omhoog/omlaag)
volatile uint8_t rpwm2_active = 0; // Rechts PWM2 actief (voor omhoog/omlaag)

/**
 * @brief Initialiseer de timer (Timer0) voor motorbediening.
 *        - Zet de timer in Normal mode.
 *        - Gebruik een prescaler van 64.
 *        - Stel een duty cycle in van 50%.
 *        - Schakel Compare Match A en Overflow interrupts in.
 */
void init_timer(void)
{
    // Zet Timer0 in Normal mode, Prescaler = 64
    TCCR0A = 0; // Normal mode
    TCCR0B = (0 << CS02) | (1 << CS01) | (1 << CS00); // Prescaler = 64

    OCR0A = 127;  // Duty cycle van 50%
    TIMSK0 = (1 << OCIE0A) | (1 << TOIE0); // Schakel Compare Match A en Overflow interrupts in
}

/**
 * Functie om de timer (Timer0) uit te schakelen
 */
void stop_timer(void)
{
    // Zet de timer uit door de prescaler bits naar 0 te zetten
    TCCR0B &= ~((1 << CS02) | (1 << CS01) | (1 << CS00)); // Stop de timer
}

/**
 * @brief Initialiseer alle benodigde pins voor motorbediening en debugfuncties.
 *        - Stel pin PB6 in als uitgang voor debug LED.
 *        - Stel motorbedieningspins (LPWM, RPWM) in als uitgangen en zet deze uit.
 *        - Stel pin 22 in als uitgang.
 *        - Stel PF1 in als invoer met pull-up weerstand (bijvoorbeeld voor een knop).
 */
void init_pins(void)
{
    // Debug LED instellen
    DDRB |= (1 << PB6);

    // Motorbedieningspins (LPWM, RPWM) instellen als uitgangen, standaard uitgeschakeld
    DDRL |= (1 << LPWM) | (1 << RPWM);
    PORTL &= ~(1 << LPWM) & ~(1 << RPWM);

    // Pin 22 (v5) instellen als uitgang
    DDRA |= (1 << vcc1);
    DDRA |= (1 << vcc2);

    // PF1 (knop) instellen als invoer met pull-up weerstand
    DDRF &= ~(1 << PF1);  // PF1 als invoer
    PORTF |= (1 << PF1);  // Pull-up weerstand inschakelen
}

/**
 * @brief Initialiseer de motorbediening door pins en timers in te stellen.
 *        Schakel globale interrupts in.
 */
void init(void)
{
    init_pins();    // Pins initialiseren
    init_timer();   // Timer initialiseren
    sei();          // Schakel globale interrupts in
}

/**
 * @brief Beweeg de motor naar links door LPWM te activeren en RPWM te deactiveren.
 */
void motorBeweegLinks(void)
{
    lpwm_active = 1; // LPWM inschakelen
    rpwm_active = 0; // RPWM uitschakelen
}

/**
 * @brief Beweeg de motor naar rechts door RPWM te activeren en LPWM te deactiveren.
 */
void motorBeweegRechts(void)
{
    rpwm_active = 1; // RPWM inschakelen
    lpwm_active = 0; // LPWM uitschakelen
}

/**
 * @brief Beweeg de motor naar beneden door RPWM2 te activeren en LPWM2 te deactiveren.
 */
void motorBeweegOmlaag(void)
{
    rpwm2_active = 1; // RPWM2 inschakelen
    lpwm2_active = 0; // LPWM2 uitschakelen
}

/**
 * @brief Beweeg de motor omhoog door LPWM2 te activeren en RPWM2 te deactiveren.
 */
void motorBeweegOmhoog(void)
{
    lpwm2_active = 1; // LPWM2 inschakelen
    rpwm2_active = 0; // RPWM2 uitschakelen
}

/**
 * @brief Stop alle motoren door alle PWM-signalen uit te schakelen.
 */
void motorStop(void)
{
    lpwm_active = 0;  // LPWM uitschakelen
    rpwm_active = 0;  // RPWM uitschakelen
    lpwm2_active = 0; // LPWM2 uitschakelen
    rpwm2_active = 0; // RPWM2 uitschakelen

    // Zet alle motorpins uit
    PORTL &= ~(1 << LPWM) & ~(1 << RPWM) & ~(1 << LPWM2) & ~(1 << RPWM2);
}

/**
 * @brief ISR (Interrupt Service Routine) voor Timer0 Compare Match A.
 *        Zet de actieve motorpins uit (PWM-signaal laag).
 */
ISR(TIMER0_COMPA_vect)
{
    PORTB &= ~(1 << PB6);
    if (lpwm_active) {
        PORTL &= ~(1 << LPWM); // LPWM uitschakelen
    }
    if (rpwm_active) {
        PORTL &= ~(1 << RPWM); // RPWM uitschakelen
    }
    if (lpwm2_active) {
        PORTL &= ~(1 << LPWM2); // LPWM2 uitschakelen
    }
    if (rpwm2_active) {
        PORTL &= ~(1 << RPWM2); // RPWM2 uitschakelen
    }
    if(isNoodknopIngedrukt()) {
        while(PINF & (1 << S1)) {
            _delay_ms(1);
            PORTB |= (1 << PB6);
            PORTL &= ~(1 << LPWM) & (1 << RPWM);
            PORTL &= ~(1 << LPWM2) & (1 << RPWM2);
        }
        PORTB &= ~(1 << PB6);
    }
}

/**
 * @brief ISR (Interrupt Service Routine) voor Timer0 Overflow.
 *        Zet de actieve motorpins aan (PWM-signaal hoog).
 */
ISR(TIMER0_OVF_vect)
{
    PORTB |= (1 << PB6);
    if (lpwm_active)
    {
        PORTL |= (1 << LPWM); // LPWM inschakelen
    }
    if (rpwm_active)
    {
        PORTL |= (1 << RPWM); // RPWM inschakelen
    }
    if (lpwm2_active)
    {
        PORTL |= (1 << LPWM2); // LPWM2 inschakelen
    }
    if (rpwm2_active)
    {
        PORTL |= (1 << RPWM2); // RPWM2 inschakelen
    }
}
