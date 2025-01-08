What Slave device do in summary: 
- Receive weight calibration data from the master device.
- Continuously measure bundle weights.
- Display real-time copy counts on the LCD screen.
- Send data to the central computer via LoRa.

📚 Explanation of the Code:

✅ 1. Initialization (setup())
LCD: Initialized for user display.
LoRa: Communication module set up for receiving calibration data.
HX711 (Load Cell): Initialized and zeroed out using tare().

✅ 2. Calibration Phase (waitForCalibration())
Listens for a calibration message from the Master (CALIBRATE:XX.XX).
Updates copyWeight with the received value.

✅ 3. Measurement Phase (measureBundle())
Measures the weight of the current bundle using the load cell.
Calculates copyCount based on copyWeight.
Displays real-time data on the LCD screen.

✅ 4. Data Transmission Phase (sendDataToCentral())
Constructs a payload (BUNDLE:<Weight>,<CopyCount>) and sends it via LoRa to the central system.
Displays a confirmation message.

✅ 5. State Management (loop())
The firmware cycles through the states: WAIT_CALIBRATION, MEASURE, and SEND_DATA.

⚡ Next Steps:
Copy and paste the code into your Arduino IDE.
Install the required libraries:
- LiquidCrystal_I2C
- LoRa
- HX711
Test communication with the Master and verify calibration reception.
Verify weight and copy count calculations.