#include <Arduino.h>
#include "ledc_init.h"

/**
 * @brief Maps a percentage value (0-100) to the duty cycle based on resolution.
 * 
 * @param percent Input percentage (0-100)
 * @param resolution Bit depth (e.g., 10 for 10-bit)
 * @return uint32_t Calculated duty cycle value
 */
uint32_t mapPercentToDuty(int percent, int resolution) {
    // Clamping logic to ensure safety (Task 2)
    if (percent > 100) percent = 100;
    if (percent < 0) percent = 0;

    uint32_t max_duty = (1 << resolution) - 1;
    return (percent * max_duty) / 100;
}

/**
 * @brief Set the Motor Speed using percentage.
 * 
 * @param channel The LEDC channel (CH_L_MOTOR or CH_R_MOTOR)
 * @param percent Speed percentage (0-100)
 */
void setMotorSpeed(int channel, int percent) {
    uint32_t duty = mapPercentToDuty(percent, MOTOR_RES);
    ledcWrite(channel, duty);
}

void initLEDC() {
    // Task 1: Resource mapping without conflicts
    // Left Motor
    ledcSetup(CH_L_MOTOR, MOTOR_FREQ, MOTOR_RES);
    ledcAttachPin(PIN_L_MOTOR, CH_L_MOTOR);

    // Right Motor
    ledcSetup(CH_R_MOTOR, MOTOR_FREQ, MOTOR_RES);
    ledcAttachPin(PIN_R_MOTOR, CH_R_MOTOR);

    // Headlight
    ledcSetup(CH_HEADLIGHT, LIGHT_FREQ, LIGHT_RES);
    ledcAttachPin(PIN_HEADLIGHT, CH_HEADLIGHT);
}

void setup() {
    Serial.begin(115200);
    initLEDC();
    Serial.println("LEDC System Initialized.");
}

void loop() {
    // Task 2: Linear acceleration demo
    for (int i = 0; i <= 100; i++) {
        setMotorSpeed(CH_L_MOTOR, i);
        setMotorSpeed(CH_R_MOTOR, i);
        delay(50);
    }
    
    delay(1000);

    for (int i = 100; i >= 0; i--) {
        setMotorSpeed(CH_L_MOTOR, i);
        setMotorSpeed(CH_R_MOTOR, i);
        delay(50);
    }

    delay(2000);
}
