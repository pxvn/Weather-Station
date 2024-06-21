/*
 * MIT License
 *
 * Copyright (c) 2024 PAVAN KALSARIYA
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#include "thingProperties.h"
#include "DHT.h"

#define DHTPIN 4 // Changed to pin 4
#define DHTTYPE DHT11

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET 4     // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); // Initialize OLED display object
DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor object

void setup() {
  Serial.begin(9600); // Start serial communication
  dht.begin(); // Start DHT sensor

  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  // Defined in thingProperties.h
  initProperties(); // Initialize Arduino IoT Cloud properties

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  // Set debug level
  setDebugMessageLevel(1);
  ArduinoCloud.printDebugInfo();

  // Initialize OLED display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("ONLINE\n\n");
  display.display();
}


void loop() {
  ArduinoCloud.update(); // Update Arduino IoT Cloud connection
  float hum = dht.readHumidity(); // Read humidity from DHT sensor
  float temp = dht.readTemperature(); // Read temperature from DHT sensor
  if (isnan(hum) || isnan(temp)) { // Check if the readings are valid
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  humidity = hum; // Update cloud variable with humidity
  tEMP = temp; // Update cloud variable with temperature

  // Your code here

  // Print temperature and humidity to serial monitor
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.println("°C");
  Serial.print("Hum: ");
  Serial.print(hum);
  Serial.println("%");
  delay(1000);
  
  // Display temperature and humidity on OLED
  display.setTextSize(1);
  display.setCursor(0,20);
  display.print("TemP: ");
  display.print(temp);
  display.println("C\n");
  display.println();
  display.setCursor(0,30);
  display.print("Hum: ");
  display.print(hum);
  display.println("%");
  display.display();
  delay(1000);
}

void onTEMPChange() {
  // Implementation for the onTEMPChange() function
  Serial.println("Temperature changed on IoT Cloud");
}

void onHumidityChange() {
  // Implementation for the onHumidityChange() function
  Serial.println("Humidity changed on IoT Cloud");
}
