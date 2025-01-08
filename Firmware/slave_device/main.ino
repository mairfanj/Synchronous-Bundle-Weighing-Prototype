#include "config.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <LoRa.h>
#include "HX711.h"

// Pin Definitions
#define LORA_SS 5          // LoRa SS pin
#define LORA_RST 14        // LoRa reset pin
#define LORA_DIO0 2        // LoRa DIO0 pin

#define LOADCELL_DOUT_PIN 4  // HX711 data pin
#define LOADCELL_SCK_PIN 15  // HX711 clock pin

// LCD Display
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C Address for LCD

// Weight Sensor
HX711 scale;

// Calibration Weight
float copyWeight = 1.0; // Default value (updated from Master)

// State Management
enum State { WAIT_CALIBRATION, MEASURE, SEND_DATA };
State currentState = WAIT_CALIBRATION;

// Bundle Data
float bundleWeight = 0.0;
int copyCount = 0;

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
  
  // Initialize Load Cell
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  if (!scale.is_ready()) {
    lcd.clear();
    lcd.print("LoadCell Error!");
    while (1);
  }
  scale.tare(); // Reset scale to 0
  
  delay(2000);
}

void loop() {
  switch (currentState) {
    case WAIT_CALIBRATION:
      waitForCalibration();
      break;
    case MEASURE:
      measureBundle();
      break;
    case SEND_DATA:
      sendDataToCentral();
      break;
  }
}

// ----------------------- Functions -----------------------

// Function: Wait for Calibration Data from Master
void waitForCalibration() {
  lcd.clear();
  lcd.print("Waiting Calib...");

  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    String received = LoRa.readString();
    if (received.startsWith("CALIBRATE:")) {
      copyWeight = received.substring(10).toFloat();
      lcd.clear();
      lcd.print("Calib: ");
      lcd.print(copyWeight);
      lcd.print("g");
      delay(2000);
      currentState = MEASURE;
    }
  }
}

// Function: Measure Bundle Weight
void measureBundle() {
  lcd.clear();
  lcd.print("Measuring...");

  if (scale.is_ready()) {
    bundleWeight = scale.get_units(5); // Take average of 5 readings
    copyCount = (int)(bundleWeight / copyWeight); // Calculate copies

    lcd.setCursor(0, 1);
    lcd.print("Copies: ");
    lcd.print(copyCount);

    delay(2000); // Display for 2 seconds

    currentState = SEND_DATA;
  } else {
    lcd.setCursor(0, 1);
    lcd.print("Sensor Error!");
    delay(2000);
  }
}

// Function: Send Data to Central Computer
void sendDataToCentral() {
  lcd.clear();
  lcd.print("Sending Data...");

  String payload = "BUNDLE:";
  payload += String(bundleWeight) + ",";
  payload += String(copyCount);

  LoRa.beginPacket();
  LoRa.print(payload);
  LoRa.endPacket();

  lcd.setCursor(0, 1);
  lcd.print("Sent OK!");

  delay(2000);
  currentState = MEASURE; // Loop back to measure next bundle
}
 
