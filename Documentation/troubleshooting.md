# Software Architecture

This document describes the software architecture for the **Synchronous Bundle Weighing Prototype**. It includes an overview of the system, module breakdowns, communication protocols, and data flow.

---

## Table of Contents

1. [Overview](#overview)
2. [System Modules](#system-modules)
   - [Master Device](#master-device)
   - [Slave Device](#slave-device)
3. [Communication Protocol](#communication-protocol)
4. [Data Flow](#data-flow)
5. [Error Handling and Debugging](#error-handling-and-debugging)

---

## Overview

The software for the **Synchronous Bundle Weighing Prototype** consists of two primary components:

1. **Master Device Firmware**: Manages calibration, user input, and LoRa communication.
2. **Slave Device Firmware**: Processes weight measurements, calculates copy counts, and transmits data to a central system.

These devices interact via the LoRa wireless communication protocol.

---

## System Modules

### **Master Device**

#### **Responsibilities**
- Detect keypad for master mode verification.
- Handle calibration input from the user.
- Transmit calibration data to slave devices.
- Display system status on the LCD.

#### **Key Components**
- **Calibration Module**: Accepts user input and calculates the weight per copy.
- **LoRa Communication**: Sends calibration data to slaves.
- **Display Handler**: Updates the LCD with status and prompts.

#### **State Management**
1. **INIT**: Initializes components.
2. **CALIBRATE**: Prompts user to place a single copy and calculates weight.
3. **BROADCAST**: Sends calibration data to all slaves.
4. **IDLE**: Waits for further user input.

### **Slave Device**

#### **Responsibilities**
- Receive calibration data from the master.
- Continuously measure bundle weights.
- Calculate the number of copies in each bundle.
- Send data to the central system.
- Display weight and copy count on the LCD.

#### **Key Components**
- **Calibration Listener**: Listens for calibration data from the master.
- **Weight Measurement**: Reads data from the load cell using HX711.
- **Data Transmission**: Sends bundle data to the central system via LoRa.
- **Display Handler**: Updates the LCD with real-time weight and copy counts.

#### **State Management**
1. **WAIT_CALIBRATION**: Awaits calibration data from the master.
2. **MEASURE**: Measures bundle weight and calculates copy count.
3. **SEND_DATA**: Transmits bundle data to the central system.

---

## Communication Protocol

The system uses **LoRa SX1278** modules for communication between the master and slave devices. Communication is implemented using a simple, reliable, and lightweight protocol.

### **Message Types**
- **Calibration Message**: Sent by the master to slaves.
  - Format: `CALIBRATE:<weight>`
  - Example: `CALIBRATE:300.5`
- **Bundle Data Message**: Sent by the slave to the central system.
  - Format: `BUNDLE:<weight>,<count>`
  - Example: `BUNDLE:1500.25,5`

### **Frequency and Settings**
- Frequency: **433 MHz**
- Bandwidth: **125 kHz**
- Spreading Factor: **SF7**
- Coding Rate: **4/5**

---

## Data Flow

### **Calibration Data Flow**
1. The master device prompts the user to place a single copy on the scale.
2. The weight is captured and broadcast to all slave devices.
3. Slaves update their internal `copyWeight` variable.

### **Measurement Data Flow**
1. The slave device measures the bundle weight using HX711.
2. The slave calculates the number of copies based on the calibration weight.
3. Data is displayed on the slave's LCD and sent to the central system via LoRa.

### **Example Data Flow**
1. **Master**:
   - User calibrates with `300.5g`.
   - Sends: `CALIBRATE:300.5`.
2. **Slave**:
   - Receives: `CALIBRATE:300.5`.
   - Measures: `1500.0g`.
   - Calculates: `5 copies`.
   - Sends: `BUNDLE:1500.0,5`.

---

## Error Handling and Debugging

### **Error Types**

| Error                     | Cause                          | Resolution                       |
|---------------------------|--------------------------------|----------------------------------|
| LoRa communication failure | Frequency mismatch            | Verify `LORA_FREQUENCY` in `config.h` |
| HX711 not responding      | Incorrect wiring or init issue | Check wiring and HX711 initialization |
| LCD not displaying        | Incorrect I2C address          | Verify and adjust `LCD_I2C_ADDR` |

### **Debugging Tips**
- Use `Serial.print()` statements to debug state transitions.
- Log LoRa packets for validation.
- Test components individually before integration.

---

*End of Software Architecture Document*
 
