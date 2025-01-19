# User Manual for Master-Slave Device Firmware

This document provides a detailed guide for setting up, calibrating, and operating the Master-Slave Device system, which consists of:

- **Master Device**: Sends calibration data and manages overall communication, including using a load cell for calibration weight measurement.
- **Slave Device**: Processes bundle weights, calculates copy counts, and transmits data to a central computer.

---

## Table of Contents

1. [System Overview](#system-overview)
2. [Hardware Setup](#hardware-setup)
3. [Software Setup](#software-setup)
4. [Calibration and Operation](#calibration-and-operation)
5. [Workflow Diagram](https://github.com/mairfanj/Synchronous-Bundle-Weighing-Prototype/blob/main/Documentation/Workflow_Diagram.md) (Will redirect to Documentation/Workflow_Diagram.md)
6. [Troubleshooting](#troubleshooting)

---

## System Overview

The Master-Slave Device system is designed for real-time measurement and data transmission. Key functionalities include:

- **Master Device**:
  - Uses a load cell to determine calibration weight.
  - Sends calibration weights to the Slave Device.
  - Acts as a communication hub.

- **Slave Device**:
  - Uses a load cell to measure bundle weights.
  - Calculates the number of copies in each bundle.
  - Displays real-time data on an LCD.
  - Sends data to a central system via LoRa.

---

## Hardware Setup

### 1. Components Required

#### Master Device
- ESP32 microcontroller
- LoRa SX1278 module
- HX711 load cell amplifier
- 50 kg load cell
- LCD1602 (I2C interface)
- 3-button membrane keypad

#### Slave Device
- ESP32 microcontroller
- LoRa SX1278 module
- HX711 load cell amplifier
- 50 kg load cell
- LCD1602 (I2C interface)

### 2. Wiring Diagram

#### Master Device
| Component         | Pin Connections  |
|-------------------|------------------|
| LoRa SS           | GPIO 5           |
| LoRa RST          | GPIO 14          |
| LoRa DIO0         | GPIO 2           |
| HX711 DOUT        | GPIO 16          |
| HX711 SCK         | GPIO 17          |
| LCD SDA           | GPIO 21          |
| LCD SCL           | GPIO 22          |
| Keypad            | GPIO 4           |

#### Slave Device
| Component         | Pin Connections  |
|-------------------|------------------|
| LoRa SS           | GPIO 5           |
| LoRa RST          | GPIO 14          |
| LoRa DIO0         | GPIO 2           |
| HX711 DOUT        | GPIO 4           |
| HX711 SCK         | GPIO 15          |
| LCD SDA           | GPIO 21          |
| LCD SCL           | GPIO 22          |

---

## Software Setup

### 1. Installing Required Libraries

Install the following libraries in the Arduino IDE:
- **LoRa**
- **LiquidCrystal_I2C**
- **HX711**

### 2. Adding Firmware Files

Upload the appropriate firmware to each device:
- **Master Device**: `master_device.ino` and `config.h`
- **Slave Device**: `slave_main.ino` and `config.h`

### 3. Configuring `config.h`

Ensure `config.h` matches your hardware configuration. Adjust pin numbers and other parameters as needed.

---

## Calibration and Operation

### 1. Calibration Phase
1. Power on both devices.
2. On the Master Device, place a single copy on its load cell for calibration.
3. The Master Device measures the weight and broadcasts the calibration data to the Slave Device.
4. The Slave Device updates its internal configuration with the received calibration weight.

### 2. Measurement Phase
1. Place a bundle on the load cell connected to the Slave Device.
2. The Slave Device measures the bundle weight and calculates the number of copies based on the calibration weight.
3. The Slave Device displays the real-time copy count and bundle weight.

### 3. Data Transmission Phase
1. The Slave Device sends the measured data to the central computer via LoRa.
2. A confirmation message is displayed on the Slave Device LCD.

---

## Troubleshooting

### 1. Common Issues

| Issue                  | Cause                          | Solution                          |
|------------------------|--------------------------------|-----------------------------------|
| LoRa communication fails | Incorrect wiring or frequency | Verify wiring and frequency in `config.h` |
| LCD not displaying text | I2C address mismatch          | Check and update `LCD_I2C_ADDR` in `config.h` |
| Load cell not measuring | HX711 not ready               | Ensure proper wiring and sensor initialization |

### 2. Debugging Tips
- Use the Serial Monitor for debugging messages.
- Confirm successful library installation.
- Test individual components before full assembly.

---

## Appendix

- **References**:
  - LoRa Library Documentation
  - HX711 Load Cell Library Guide
  - LiquidCrystal_I2C Library Examples

- **License**:
  - This project is open-source under the MIT License.

---

*End of User Manual*
