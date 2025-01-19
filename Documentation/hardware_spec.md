# Hardware Specifications

This document outlines the hardware components and specifications required for the Master-Slave Device system used in the **Synchronous Bundle Weighing Prototype**.

---

## Table of Contents

1. [Master Device Hardware](#master-device-hardware)
2. [Slave Device Hardware](#slave-device-hardware)
3. [Shared Components](#shared-components)
4. [Power Requirements](#power-requirements)
5. [Hardware Diagrams](#hardware-diagrams)

---

## Master Device Hardware

The Master Device is responsible for:
- Sending calibration data.
- Managing system communication.

### **Required Components**

| Component               | Specification                                | Quantity |
|-------------------------|----------------------------------------------|----------|
| Microcontroller         | ESP32 (or equivalent)                       | 1        |
| LoRa Module             | SX1278 (433 MHz)                            | 1        |
| LCD Display             | 16x2 (I2C Interface, 0x27 default address)  | 1        |
| 3-Button Keypad         | Membrane keypad                             | 1        |
| Power Supply            | 5V/2A (Micro-USB or equivalent)             | 1        |

### **Pin Configuration**

| Component      | Pin Assignments |
|----------------|-----------------|
| LoRa SS        | GPIO 5          |
| LoRa RST       | GPIO 14         |
| LoRa DIO0      | GPIO 2          |
| LCD SDA        | GPIO 21         |
| LCD SCL        | GPIO 22         |
| Keypad         | GPIO 4          |

---

## Slave Device Hardware

The Slave Device is responsible for:
- Measuring bundle weight.
- Sending data to the Master Device.

### **Required Components**

| Component               | Specification                                | Quantity |
|-------------------------|----------------------------------------------|----------|
| Microcontroller         | ESP32 (or equivalent)                       | 1        |
| LoRa Module             | SX1278 (433 MHz)                            | 1        |
| HX711 Load Cell Module  | 24-bit ADC for weight measurement           | 1        |
| Load Cell Sensor        | 50 kg capacity                              | 1        |
| LCD Display             | 16x2 (I2C Interface, 0x27 default address)  | 1        |
| Power Supply            | 5V/2A (Micro-USB or equivalent)             | 1        |

### **Pin Configuration**

| Component         | Pin Assignments |
|-------------------|-----------------|
| LoRa SS           | GPIO 5          |
| LoRa RST          | GPIO 14         |
| LoRa DIO0         | GPIO 2          |
| HX711 DOUT        | GPIO 4          |
| HX711 SCK         | GPIO 15         |
| LCD SDA           | GPIO 21         |
| LCD SCL           | GPIO 22         |

---

## Shared Components

Some components are shared or interchangeable between the Master and Slave devices:

| Component       | Specification        |
|-----------------|----------------------|
| LoRa Module     | SX1278, 433 MHz     |
| LCD Display     | 16x2, I2C Interface |
| Power Supply    | 5V/2A               |

---

## Power Requirements

### **Master Device Power**
- Voltage: 5V
- Current: ~500 mA
- Power Source: USB adapter or battery pack

### **Slave Device Power**
- Voltage: 5V
- Current: ~800 mA (including HX711 and LoRa module)
- Power Source: USB adapter or battery pack

---

## Hardware Diagrams

### **Master Device Schematic**

*(Insert wiring diagram for Master Device)*

### **Slave Device Schematic**

*(Insert wiring diagram for Slave Device)*

---

## Notes

- Ensure proper grounding for all components.
- Use shielded cables for LoRa modules to minimize interference.
- Verify I2C addresses for LCDs to avoid conflicts.

*End of Document*
 
