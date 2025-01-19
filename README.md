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
[Workflow Diagram](https://github.com/mairfanj/Synchronous-Bundle-Weighing-Prototype/blob/main/Documentation/Workflow_Diagram.md) (Redirect to Documentation
/Workflow_Diagram.md)

## 🚦 How to Get Started  
1. Clone the repository:  
   ```bash
   git clone https://github.com/mairfanj/Synchronous-Bundle-Weighing-Prototype.git
2. Install dependencies (e.g., Arduino libraries for HX711, LoRa, etc.).
3. Upload firmware to Master and Slave ESP32 devices.
4. Follow the user manual in Documentation/user_manual.md.

## 📈 Simulation (Wokwi)
You can simulate parts of this project using Wokwi.
Open the Wokwi project file from Simulation/wokwi_project.json.

## 🤝 Contributions
Contributions are welcome! Please read the CONTRIBUTING.md for details.

## 📄 License
This project is licensed under the MIT License.
