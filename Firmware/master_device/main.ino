#include "config.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <LoRa.h>
#include "HX711.h"

// LCD Display
LiquidCrystal_I2C lcd(LCD_I2C_ADDR, LCD_COLUMNS, LCD_ROWS);

// Load Cell
HX711 scale;

// State Management
enum State { INIT, CALIBRATE, BROADCAST, IDLE };
State currentState = INIT;

// Variables
float copyWeight = 0.0; // Calibration weight for one copy
bool isMaster = false;  // Master mode flag

void setup() {
  Serial.begin(SERIAL_BAUD_RATE);

  // Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Initializing...");

  // Initialize LoRa
  LoRa.setPins(LORA_SS, LORA_RST, LORA_DIO0);
  if (!LoRa.begin(LORA_FREQUENCY)) {
    lcd.setCursor(0, 1);
    lcd.print("LoRa Failed!");
    while (1);
  }
  lcd.setCursor(0, 1);
  lcd.print("LoRa OK!");

  // Initialize HX711
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  if (!scale.is_ready()) {
    lcd.clear();
    lcd.print("HX711 Error!");
    while (1);
  }
  scale.tare();

  // Check if keypad is connected
  pinMode(KEYPAD_PIN, INPUT_PULLUP);
  if (digitalRead(KEYPAD_PIN) == LOW) {
    isMaster = true;
    lcd.clear();
    lcd.print("Mode: Master");
    delay(2000);
    currentState = CALIBRATE;
  } else {
    lcd.clear();
    lcd.print("No Keypad Found");
    lcd.setCursor(0, 1);
    lcd.print("Slave Mode Only");
    while (1);
  }
}

void loop() {
  switch (currentState) {
    case CALIBRATE:
      calibrateDevice();
      break;
    case BROADCAST:
      broadcastCalibration();
      break;
    case IDLE:
      idleState();
      break;
    default:
      break;
  }
}

void calibrateDevice() {
  lcd.clear();
  lcd.print("Calibrate...");
  lcd.setCursor(0, 1);
  lcd.print("Place 1 Copy");

  delay(5000); // Wait for user to place a copy

  if (scale.is_ready()) {
    copyWeight = scale.get_units(10); // Average of 10 readings
    lcd.clear();
    lcd.print("Weight: ");
    lcd.print(copyWeight);
    lcd.print("g");
    delay(2000);
    currentState = BROADCAST;
  } else {
    lcd.clear();
    lcd.print("HX711 Error");
    delay(2000);
  }
}

void broadcastCalibration() {
  lcd.clear();
  lcd.print("Broadcasting...");

  LoRa.beginPacket();
  LoRa.print("CALIBRATE:");
  LoRa.print(copyWeight);
  LoRa.endPacket();

  lcd.setCursor(0, 1);
  lcd.print("Sent to Slaves");
  delay(2000);
  currentState = IDLE;
}

void idleState() {
  lcd.clear();
  lcd.print("Master: IDLE");
  delay(1000);
}
