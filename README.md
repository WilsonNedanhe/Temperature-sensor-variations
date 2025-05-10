ESP32 Weather Monitoring System with DHT11 and ThingSpeak

Overview

This project demonstrates how to build a simple IoT-based weather monitoring station using:

ESP32 Development Board

DHT11 Temperature & Humidity Sensor

ThingSpeak IoT Platform

The ESP32 reads temperature and humidity data from the DHT11 sensor and uploads it to ThingSpeak every 15 seconds, allowing real-time visualization and data logging.

Features

Reads temperature and humidity using DHT11

Sends data to ThingSpeak cloud

Real-time monitoring via ThingSpeak charts

Easy-to-extend modular Arduino code

Beginner-friendly hardware setup

Components Used

Component Description

ESP32 Wi-Fi-enabled microcontroller DHT11 Sensor Measures temperature & humidity Breadboard & Wires For prototyping 10kΩ Resistor Pull-up for DHT11 data pin Micro-USB Cable For programming ESP32

Circuit Diagram

DHT11 → ESP32 VCC → [3.3]V GND → GND DATA → GPIO 4 (with 10k pull-up to VCC)

Software Setup

    Arduino IDE Setup

Install Arduino IDE

Install ESP32 board support

Install the following libraries:

DHT sensor library by Adafruit

Adafruit Unified Sensor

ThingSpeak by MathWorks

    ThingSpeak Setup:

Create a free account at ThingSpeak

Create a new channel with two fields:

Field 1: Temperature

Field 2: Humidity

Copy your Write API Key

    Configure Code

Open the Arduino sketch (ESP32_DHT11_ThingSpeak.ino)

Replace:

YOUR_SSID with your Wi-Fi name

YOUR_PASSWORD with your Wi-Fi password

YOUR_CHANNEL_ID and YOUR_WRITE_API_KEY with your ThingSpeak credentials

Upload & Monitor:

Connect your ESP32 to your PC via USB.

Select the correct board and port in Arduino IDE.

Upload the sketch.

Open Serial Monitor at [115200] baud to see status logs.

Sample Output on Serial Monitor :

Temperature: 26.5 °C Humidity: 55.2 % Data successfully sent to ThingSpeak

Future Improvements :

Add OLED display for offline data display

Store data on SD card as backup

Add more sensors (e.g., BMP[280] for pressure, MQ[135] for air quality)

Use deep sleep for battery-powered setups

License

This project is open-source under the MIT License.
