#ifndef CONFIG_H
#define CONFIG_H

// ----- LoRa Settings -----
#define LORA_SS 5          // LoRa SS pin
#define LORA_RST 14        // LoRa reset pin
#define LORA_DIO0 2        // LoRa DIO0 pin
#define LORA_FREQUENCY 433E6  // Frequency in MHz

// ----- Load Cell Settings -----
#define LOADCELL_DOUT_PIN 4  // HX711 data pin
#define LOADCELL_SCK_PIN 15  // HX711 clock pin

// ----- LCD Settings -----
#define LCD_I2C_ADDR 0x27  // I2C Address for LCD
#define LCD_COLUMNS 16     // Number of columns
#define LCD_ROWS 2         // Number of rows

// ----- Other Settings -----
#define DEFAULT_COPY_WEIGHT 1.0  // Default weight per copy in grams

#endif // CONFIG_H
 
