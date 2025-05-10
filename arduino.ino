#include <WiFi.h>
#include <ThingSpeak.h>
#include "DHT.h"

// Replace with your network credentials
const char* ssid = "xx--xx--xx";
const char* password ="xxxx--xxxx--xxxx";

// ThingSpeak settings
unsigned long channelID = -----; 
const char* writeAPIKey = "---------------"; 

// DHT11 settings
#define DHTPIN 21         
#define DHTTYPE DHT11    
DHT dht(DHTPIN, DHTTYPE);

// WiFi and ThingSpeak clients
WiFiClient client;

void setup() {
  Serial.begin(115200);
  dht.begin();

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to Wi-Fi");

  // Initialize ThingSpeak
  ThingSpeak.begin(client);
}

void loop() {
  // Read temperature and humidity
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check if readings are valid
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000);
    return;
  }

  // Print readings to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C\tHumidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Write data to ThingSpeak
  ThingSpeak.setField(1, temperature);
  ThingSpeak.setField(2, humidity);

  int statusCode = ThingSpeak.writeFields(channelID, writeAPIKey);
  if (statusCode == 200) {
    Serial.println("Data successfully sent to ThingSpeak");
  } else {
    Serial.print("Error sending data to ThingSpeak. HTTP error code: ");
    Serial.println(statusCode);
  }

  // Wait 15 seconds before sending the next set of data
  delay(15000);
}
