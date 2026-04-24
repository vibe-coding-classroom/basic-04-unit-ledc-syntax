# API Documentation: LEDC Motor Control

This document explains the abstraction layer created for motor control using ESP32's LEDC peripheral.

## Core API: `setMotorSpeed(int channel, int percent)`

The goal of this API is to hide the complexity of bit depths and duty cycle calculations from the higher-level logic.

### 1. Mathematical Mapping
The conversion from percentage to duty cycle follows this formula:
$$Duty = \frac{Percent \times (2^{Resolution} - 1)}{100}$$

For a **10-bit** resolution (as used in this project):
- 0% = 0
- 50% = 511
- 100% = 1023

### 2. Boundary Handling (Clamping)
To prevent unexpected behavior (like integer overflow or motor spikes), the API implements "Clamping":
- Inputs $> 100$ are capped at 100.
- Inputs $< 0$ are floored at 0.

### 3. Resource Management
The system uses separate LEDC Timers for motors and lights to allow different frequencies:
- **Motor Frequency**: 20kHz (to avoid audible high-pitched noise).
- **Light Frequency**: 5kHz (standard for non-flicker LED control).
