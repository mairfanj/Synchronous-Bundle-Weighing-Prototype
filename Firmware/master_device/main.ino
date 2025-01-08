#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <LoRa.h>

// Pin Definitions
#define KEYPAD_PIN 4       // Example pin for keypad connection
#define LORA_SS 5          // LoRa SS pin
#define LORA_RST 14        // LoRa reset pin
#define LORA_DIO0 2        // LoRa DIO0 pin

// LCD Display
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C Address for LCD

// Keypad Flags
bool isMaster = false;

// Weight Measurement (Placeholder, replace with actual sensor logic)
float copyWeight = 0.0;

// State Management
enum State { INIT, CALIBRATE, BROADCAST, IDLE };
State currentState = INIT;

void setup() {
  Serial.begin(115200);
  
  // Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Initializing...");
  
  // Initialize LoRa
  LoRa.setPins(LORA_SS, LORA_RST, LORA_DIO0);
  if (!LoRa.begin(433E6)) {
    lcd.setCursor(0, 1);
    lcd.print("LoRa Failed!");
    while (1);
  }
  
  lcd.setCursor(0, 1);
  lcd.print("LoRa OK!");

  // Check if Keypad is Connected (Master Mode Check)
  pinMode(KEYPAD_PIN, INPUT_PULLUP);
  if (digitalRead(KEYPAD_PIN) == LOW) {
    isMaster = true;
    lcd.clear();
    lcd.print("Mode: Master");
    delay(2000);
  } else {
    lcd.clear();
    lcd.print("No Keypad Found");
    lcd.setCursor(0, 1);
    lcd.print("Slave Mode Only");
    while (1); // Halt, as it's not in master mode
  }

  currentState = CALIBRATE;
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
      lcd.setCursor(0, 0);
      lcd.print("Master: IDLE");
      delay(1000);
      break;
  }
}

// ----------------------- Functions -----------------------

// Function: Calibrate Device
void calibrateDevice() {
  lcd.clear();
  lcd.print("Calibrate...");
  lcd.setCursor(0, 1);
  lcd.print("Place 1 Copy");

  // Simulate Weight Input
  delay(5000); // Wait for user to place a copy (replace with sensor code)
  copyWeight = 300.5; // Example weight in grams

  lcd.clear();
  lcd.print("Weight: ");
  lcd.print(copyWeight);
  lcd.print("g");

  delay(2000); // Wait for confirmation

  currentState = BROADCAST;
}

// Function: Broadcast Calibration Data
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
 
