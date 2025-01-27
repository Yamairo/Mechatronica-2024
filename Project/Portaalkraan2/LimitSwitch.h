#ifndef LIMIT_SWITCH_H
#define LIMIT_SWITCH_H

#include <avr/io.h>
#include <util/delay.h>

// Function prototypes
int isLimitSwitchPressed(uint8_t inputPin, volatile uint8_t *inputPort, volatile uint8_t *pinReg);
uint16_t countLimitSwitchPresses(uint8_t inputPin, volatile uint8_t *inputPort, volatile uint8_t *pinReg);

#endif // LIMIT_SWITCH_H
