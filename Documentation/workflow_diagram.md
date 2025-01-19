# Workflow Diagram

This document illustrates the workflow of the **Synchronous Bundle Weighing Prototype** system, highlighting the interaction between the Master Device and Slave Device, along with the overall data flow.
![Full Workflow](https://github.com/mairfanj/Synchronous-Bundle-Weighing-Prototype/blob/main/Documentation/full_flowchart_mermaid-2.png?raw=true)

## Key Interactions

### 1. **Master to Slave Communication**
- **Message Type**: Calibration Data
- **Format**: `CALIBRATE:<weight>`
- **Purpose**: Informs slaves about the weight per copy.

### 2. **Slave to Central System Communication**
- **Message Type**: Bundle Data
- **Format**: `BUNDLE:<weight>,<copies>`
- **Purpose**: Sends measured bundle weight and calculated copy count.

---

## Notes

- The workflow ensures real-time synchronization and minimal user intervention after calibration.
- Ensure proper power supply and communication settings to maintain workflow integrity.

*End of Workflow Diagram Document*
 
