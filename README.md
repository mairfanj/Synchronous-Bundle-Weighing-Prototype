# Synchronous-Bundle-Weighing-Prototype
A project for real-time weighing and data synchronization in a newspaper production line using ESP32 and LoRa communication.

# 📊 **Synchronous Bundle Weighing Prototype**

## 🚀 Project Overview  
This project aims to streamline newspaper bundle weighing in a fast-paced production line environment using ESP32 microcontrollers, load cells, and LoRa communication.  

## 🛠️ Hardware Components  
- ESP32-C3 Development Boards  
- HX711 Load Cell Module  
- 50kg Load Cell Sensors  
- LCD1602 Display (I2C)  
- LoRa SX1278 Module (433MHz)  
- 3-Button Membrane Keypad  

## 🧠 Key Features  
- Real-time weight measurement for newspaper bundles.  
- Data synchronization between Master and Slave devices using LoRa.  
- Automatic data logging to CSV/Excel files.  
- Easy calibration and configuration from Master Device.  

## 🖥️ Software Overview  
- Master Firmware: Controls calibration and weight data distribution.  
- Slave Firmware: Processes and displays weight data, sends logs to the central system.  
- Data Logging: Periodic logging to CSV/Excel via Serial communication.

## 📊 Workflow Diagram  
![Workflow Diagram](./Images/circuit_diagram.png)

## 🚦 How to Get Started  
1. Clone the repository:  
   ```bash
   git clone https://github.com/yourusername/Synchronous-Bundle-Weighing-Prototype.git
