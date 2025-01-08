📚 Explanation of the Code:

✅ 1. Initialization (setup())
LCD: Initialized for user display.
LoRa: Communication module is set up.
Master Mode Detection: The device detects if a keypad is connected. If not, it halts execution.

✅ 2. Calibration (calibrateDevice())
Prompt the user to place one copy on the scale.
Simulates weight measurement (copyWeight).

✅ 3. Broadcast Calibration Data (broadcastCalibration())
Sends calibration data (copyWeight) to all slave devices via LoRa.
Displays a confirmation message.

✅ 4. State Management (loop())
The loop() function cycles through the states: CALIBRATE, BROADCAST, and IDLE.

⚡ Next Steps:
Copy and paste the code into your Arduino IDE.
Install the required libraries:
- LiquidCrystal_I2C
- LoRa
Test the calibration flow.
Ensure the LoRa message is broadcast successfully. 
