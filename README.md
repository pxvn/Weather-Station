# ARDUINO IOT CLOUD BASED Smart Temp & Humidity Monitoring with ESP32 & DHT11

<p align="center">
  <img src="https://views.whatilearened.today/views/github/pxvn/ESP32-DHT-OLED-Arduino-Cloud-Monitoring.svg" alt="ViewCount" />
  <img src="https://img.shields.io/badge/License-MIT-yellow.svg" alt="License: MIT" />
  <img src="https://img.shields.io/badge/Arduino-Cloud-blue.svg" alt="Arduino Cloud" />
  <img src="https://img.shields.io/badge/ESP32-PlatformIO-blue.svg" alt="ESP32" />
  <img src="https://img.shields.io/badge/DHT11-Sensor-green.svg" alt="DHT11 Sensor" />
  <img src="https://img.shields.io/badge/Adafruit-GFX-orange.svg" alt="Adafruit GFX" />
  <img src="https://img.shields.io/badge/SSD1306-OLED-yellow.svg" alt="SSD1306 OLED" />
  <img src="https://img.shields.io/github/last-commit/pxvn/ESP32-DHT-OLED-Arduino-Cloud-Monitoring" />
  <img src="https://img.shields.io/badge/Code-Verified%20%26%20Tested-success"/>

</p>


Welcome to the ESP32-based temperature and humidity monitoring system project! 🌡️💧

This system uses a DHT sensor and an OLED display, integrated with Arduino IoT Cloud for remote monitoring.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Hardware Required](#hardware-required)
- [Software Setup](#software-setup)
- [Installation](#installation)
- [Usage](#usage)
- [Code Explanation](#code-explanation)
- [License](#license)

## Introduction

This project demonstrates how to use an ESP32 microcontroller to monitor temperature and humidity using a DHT sensor. The data is displayed on an OLED screen and can be monitored remotely via the Arduino IoT Cloud.

![System Overview](images/system_overview.png)

## Features

✨ **Real-time temperature and humidity monitoring**  
📟 **OLED display for local data visualization**  
🌐 **Remote monitoring through Arduino IoT Cloud**  
🔧 **Easy to set up and use**

## Possible Uses

| Use Case                                  | Description                                              |
|-------------------------------------------|----------------------------------------------------------|
| Home Temperature Monitoring               | Monitor the temperature and humidity levels in your home to ensure comfort.                                           |
| Greenhouse Automation                     | Control the environment in a greenhouse by monitoring temperature and humidity levels.                                           |
| Industrial Monitoring                     | Monitor environmental conditions in industrial settings to ensure worker safety and equipment efficiency. |
| Agriculture                               | Monitor temperature and humidity levels in agricultural settings to optimize crop growth.             |
| Data Center Environment Monitoring        | Monitor temperature and humidity in data centers to prevent equipment overheating and failure.        |
| HVAC Systems Control                      | Use sensor data to control heating, ventilation, and air conditioning systems for optimal comfort and energy efficiency. |



## Hardware Required

| Component                  | Quantity |
|----------------------------|----------|
| ESP32 development board    | 1        |
| DHT11 or DHT22 sensor      | 1        |
| 0.96 inch OLED display     | 1        |
| Breadboard and jumper wires| 1 set    |
| USB cable                  | 1        |

![Hardware Setup](images/hardware_setup.png)

## Software Setup

### Arduino IoT Cloud

1. Create an account on [Arduino IoT Cloud]([https://create.arduino.cc/iot](https://login.arduino.cc/login?state=hKFo2SBXRkRTMUpXeU0yZzJwYmRTWHMxV0dvVmlTT2taQ1BTLaFupWxvZ2luo3RpZNkgWHBnUm5xTElIOTJMYTlERWNkbFFJMUpsaWZGb19leUajY2lk2SBlOXFpcEEyTjBrOVA4dnZyZTlmZEdjNnU5S2w5ZUhTUA&client=e9qipA2N0k9P8vvre9fdGc6u9Kl9eHSP&protocol=oauth2&scope=openid+profile+email&redirect_uri=https%3A%2F%2Fapp.arduino.cc&response_type=code&response_mode=query&nonce=WkJOZU1DMXFNdm9sZnRVUUkyNjVpQkc4QldSSThsSUl2TmFhdEZFbk9BZA%3D%3D&code_challenge=IMd_pOLLHEdkcaM2Kd2XA0BHyR4Fc0ww3T4TEUQxUv8&code_challenge_method=S256&auth0Client=eyJuYW1lIjoiYXV0aDAtc3BhLWpzIiwidmVyc2lvbiI6IjIuMS4zIn0%3D#/sso/login)).
2. Set up a new device and configure the ESP32.
3. Create a new Thing and add the necessary variables for temperature and humidity.

For detailed instructions on using the Arduino Cloud Editor, refer to the [Arduino Cloud Editor Setup Guide](https://docs.arduino.cc/arduino-cloud/guides/editor/).

Once your project is set up, you can monitor the data remotely through the [Arduino IoT Cloud Dashboard](https://docs.arduino.cc/arduino-cloud/guides/overview/). If you're using the Cloud Editor for the first time, make sure to install the [Arduino Create Agent](https://create.arduino.cc/getting-started/plugin/welcome) for seamless integration with your Arduino devices.

![Arduino IoT Cloud Setup](images/arduino_cloud_setup.png)

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/pxvn/ESP32-DHT-OLED-Arduino-Cloud-Monitoring.git
   cd ESP32-DHT-OLED-Arduino-Cloud-Monitoring



2.Open the project in Arduino Cloud Editor.

3.Connect the ESP32 to your computer via USB.

4.Configure the code in Arduino Cloud Editor.

5.Upload the code to the ESP32 using Arduino Cloud.

# Usage

Power on the ESP32.

The OLED display will show the current temperature and humidity.

Monitor the data remotely via the Arduino IoT Cloud dashboard.


## Code Explanation

```cpp
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
```

# Explanation of the Code

## Include Libraries
The code includes necessary libraries for the project functionality. For example:

thingProperties.h: Contains properties for interacting with Arduino IoT Cloud.

DHT.h: Library for DHT sensor communication.

This section sets up the environment and initializes required libraries and components for the project.

## Setup Function

Initializes the serial communication for debugging.

Begins the DHT sensor.

Initializes the properties and connects to Arduino IoT Cloud.

Initializes the OLED display and prints "ONLINE" to indicate the system is ready.

## Loop Function

Updates the Arduino Cloud connection.

Reads the temperature and humidity from the DHT sensor.

Updates the cloud variables with the sensor readings.

Prints the sensor readings to the serial monitor.

Displays the sensor readings on the OLED screen.

onTEMPChange and onHumidityChange: Placeholder functions that can be implemented to handle changes in temperature and humidity reported to the IoT Cloud.

## Flowchart
ESP32-DHT-OLED-Arduino-Cloud-Monitoring Flowchart:
![ed8ebf98-2562-427e-9157-f7fcab0fbe02](https://github.com/pxvn/ESP32-DHT-OLED-Arduino-Cloud-Monitoring/assets/161462414/4535a39a-17eb-410d-a9f2-cb2d8e2f6788)

## License 
[MIT License](LICENSE)
