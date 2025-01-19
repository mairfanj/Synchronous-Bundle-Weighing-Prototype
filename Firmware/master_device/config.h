#ifndef CONFIG_H
#define CONFIG_H

// ----- LoRa Settings -----
#define LORA_SS 5            // LoRa SS pin
#define LORA_RST 14          // LoRa reset pin
#define LORA_DIO0 2          // LoRa DIO0 pin
#define LORA_FREQUENCY 433E6 // Frequency in MHz

// ----- LCD Settings -----
#define LCD_I2C_ADDR 0x27    // I2C Address for LCD
#define LCD_COLUMNS 16       // Number of columns
#define LCD_ROWS 2           // Number of rows

// ----- Load Cell Settings -----
#define LOADCELL_DOUT_PIN 16 // HX711 data pin
#define LOADCELL_SCK_PIN 17  // HX711 clock pin

// ----- Keypad Settings -----
#define KEYPAD_PIN 4         // Pin connected to the keypad (used for master detection)

// ----- General Settings -----
#define SERIAL_BAUD_RATE 115200 // Serial communication baud rate

#endif // CONFIG_H
