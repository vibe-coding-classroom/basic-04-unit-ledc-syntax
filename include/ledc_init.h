#ifndef LEDC_INIT_H
#define LEDC_INIT_H

#include <Arduino.h>

// LEDC Channel Definitions
#define CH_L_MOTOR     0
#define CH_R_MOTOR     1
#define CH_HEADLIGHT   2

// LEDC Timer Configurations
#define MOTOR_FREQ     20000  // 20kHz for motors (out of human hearing range)
#define LIGHT_FREQ     5000   // 5kHz for LEDs

// LEDC Resolution (Bits)
#define MOTOR_RES      10     // 10-bit resolution (0-1023)
#define LIGHT_RES      8      // 8-bit resolution (0-255)

// Pin Definitions (Example mappings, adjust as needed for hardware)
#define PIN_L_MOTOR    18
#define PIN_R_MOTOR    19
#define PIN_HEADLIGHT  21

/**
 * @brief Initializes the LEDC peripherals with defined channels and frequencies.
 */
void initLEDC();

#endif // LEDC_INIT_H
