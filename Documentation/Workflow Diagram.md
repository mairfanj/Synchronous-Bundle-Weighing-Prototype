# Workflow Diagram

This document illustrates the workflow of the **Synchronous Bundle Weighing Prototype** system, highlighting the interaction between the Master Device and Slave Device, along with the overall data flow.

---

## System Workflow Overview

The system workflow is divided into three main phases:
1. **Initialization Phase**
2. **Calibration Phase**
3. **Operation Phase**

Each phase involves specific interactions between the devices and subsystems.

---

## Workflow Diagram

1. **Initialization Phase**

![Initialization Phase](https://github.com/mairfanj/Synchronous-Bundle-Weighing-Prototype/blob/main/Documentation/initialized_phase_flowchart.png?raw=true)

2. **Calibration Phase**

![Calibration Phase](https://github.com/mairfanj/Synchronous-Bundle-Weighing-Prototype/blob/main/Documentation/calibration_phase_flowchart.png?raw=true)

3. **Operation Phase**

![Operation Phase](https://github.com/mairfanj/Synchronous-Bundle-Weighing-Prototype/blob/main/Documentation/operation_flowchart.png?raw=true)

### Explanation
1. **Initialization Phase**:
   - Devices are powered on and initialized.
   - Master and Slave devices set up their peripherals (LCD, LoRa, HX711).

2. **Calibration Phase**:
   - The Master Device measures the weight of a single copy using its load cell.
   - Calibration data is broadcasted to all Slave Devices via LoRa.
   - Slaves update their internal configurations with the calibration weight.

3. **Operation Phase**:
   - The Slave Device measures bundle weights and calculates copy counts.
   - Data is displayed on the Slave LCD and transmitted to the central system via LoRa.
   - The Master Device logs received data and updates its display.

---

## Notes

- The workflow ensures real-time synchronization and minimal user intervention after calibration.
- Ensure proper power supply and communication settings to maintain workflow integrity.

*End of Workflow Diagram Document*
