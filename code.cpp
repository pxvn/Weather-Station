/*
 * MIT License - Copyright (c) 2024 PAVAN KALSARIYA
 * 
 * Granting permission for free use, modification, distribution, etc. of this software, 
 * with the condition that this copyright notice is included. 
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT ANY WARRANTY.
 */


#include "thingProperties.h"
#include "DHT.h"

#define DHTPIN 4 
#define DHTTYPE DHT11

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 /
#define OLED_RESET 4     
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); 
DHT dht(DHTPIN, DHTTYPE); 
void setup() {
  Serial.begin(9600); 
  dht.begin(); 
  delay(1500);

  initProperties(); // Initialize Arduino IoT Cloud 

  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

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
  ArduinoCloud.update(); 
  float hum = dht.readHumidity(); 
  float temp = dht.readTemperature(); // Read temperature from DHT sensor
  if (isnan(hum) || isnan(temp)) { 
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  humidity = hum; 
  tEMP = temp; 


  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.println("°C");
  Serial.print("Hum: ");
  Serial.print(hum);
  Serial.println("%");
  delay(1000);
  
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
  Serial.println("Temperature changed on IoT Cloud");
}

void onHumidityChange() {
  Serial.println("Humidity changed on IoT Cloud");
}
