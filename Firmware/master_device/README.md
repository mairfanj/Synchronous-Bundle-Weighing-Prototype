What Master device do in summary:
- Detect if the 3-key membrane keypad is connected.
- Display master status and allow calibration input.
- Capture weight for one copy of the newspaper.
- Broadcast the calibration data to slaves via LoRa.
- Display status on the LCD screen.

📚 Explanation of the Code:

✅ 1. Initialization (setup())
- LCD: Initialized for user display.
- LoRa: Communication module is set up.
- Master Mode Detection: The device detects if a keypad is connected. If not, it halts execution.

✅ 2. Calibration (calibrateDevice())
- Prompt the user to place one copy on the scale.
- Simulates weight measurement (copyWeight).

✅ 3. Broadcast Calibration Data (broadcastCalibration())
- Sends calibration data (copyWeight) to all slave devices via LoRa.
- Displays a confirmation message.

✅ 4. State Management (loop())
- The loop() function cycles through the states: CALIBRATE, BROADCAST, and IDLE.

⚡ Next Steps:
1) Copy and paste the code into your Arduino IDE.
2) Install the required libraries:
- LiquidCrystal_I2C
- LoRa
3) Test the calibration flow.
4) Ensure the LoRa message is broadcast successfully. 
