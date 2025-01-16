 #ifndef MOTOR_H
 #define MOTOR_H

 #include <avr/io.h>
 #include <util/delay.h>
 #include <avr/interrupt.h>
 // Pin Definitions
 #define LPWM PL5 // Pin 44
 #define RPWM PL3 // Pin 46
 #define V5 PA0 // Pin 22
 // Function Prototypes
 /**
 * @brief Initialiseerd de timer voor PWM controle.
 */
 void init_timer(void);
 /**
 * @brief Configureer de pins voor motor besturing en controle.
 */
 void init_pins(void);
 /**
 * @brief Initialiseerd de timer en de pins.
 */
 void init(void);
 // Interrupt Service Routines (ISRs)
 /**
 * @brief ISR voor Compare match A.
 */
 ISR(TIMER0_COMPA_vect);
 /**
 * @brief ISR voor TIMER0 Overflow.
 */
 ISR(TIMER0_OVF_vect);
 /**
 * @brief Enables PWM for LPWM (Pin 44).
 */
 void motorBeweegLinks(void);
 /**
 * @brief Enables PWM for RPWM (Pin 46).
*/
 void motorBeweegRechts(void);
 /**
 * @brief Disables both LPWM and RPWM outputs.
 */
 void motorStop(void);
 #endif // MOTOR_H
