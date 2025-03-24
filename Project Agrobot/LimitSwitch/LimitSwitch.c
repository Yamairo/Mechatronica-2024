#include "LimitSwitch.h"
#include <util/delay.h> // For debouncing delay

int isLimitSwitchPressed(uint8_t inputPin, volatile uint8_t *inputPort, volatile uint8_t *pinReg) {
    // Configure the input pin with pull-up resistor
    *inputPort |= (1 << inputPin); // Enable pull-up resistor

    // Check if the button is pressed
    if (!(*pinReg & (1 << inputPin))) { // Input pin LOW (button pressed)
        return 1; // Button is pressed
    } else { // Input pin HIGH (button not pressed)
        return 0; // Button is not pressed
    }
}

uint16_t countLimitSwitchPresses(uint8_t inputPin, volatile uint8_t *inputPort, volatile uint8_t *pinReg) {
    static uint16_t pressCount = 0; // Persistent count of presses
    static uint8_t wasPressed = 0; // Tracks the previous state of the button

    // Configure the input pin with pull-up resistor
    *inputPort |= (1 << inputPin); // Enable pull-up resistor

    // Check if the button is currently pressed
    if (!(*pinReg & (1 << inputPin))) { // Button is pressed
        if (!wasPressed) { // Detect transition from not pressed to pressed
            pressCount++;  // Increment the press count
            wasPressed = 1; // Mark the button as pressed
            _delay_ms(50);  // Simple debounce delay
        }
    } else { // Button is not pressed
        wasPressed = 0; // Reset the pressed state
    }

    return pressCount;
}
