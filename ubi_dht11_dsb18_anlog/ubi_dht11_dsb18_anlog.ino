

#include "Ubidots.h"

#include "DHT.h"
#define DHTPIN D1  
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);
////////////////////////////////////////////////////
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS D2  // Define the GPIO pin where the DS18B20 sensor is connected
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
/////////////////////////////////////////////////////////////
const char* DEVICE_TYPE = "esp8266x1";     // Edit here your device type label
const char* WIFI_SSID = "Ishu";           // Put here your Wi-Fi SSID
const char* WIFI_PASS = "1234567890";           // Put here your Wi-Fi password

const char* UBIDOTS_TOKEN = "BBFF-6RNW5cSXxaGRdi0QHMChRR5Jir480u";  // Put here your Ubidots TOKEN
Ubidots ubidots(UBIDOTS_TOKEN, UBI_HTTP);
#define apin A0
int reading = 0;
void setup() {
  Serial.begin(115200);
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
  ubidots.setDeviceType(DEVICE_TYPE);
  // ubidots.setDebug(true);  // Uncomment this line for printing debug messages
}

void loop() {
    delay(2000);
  float x = dht.readHumidity();
  float y = dht.readTemperature();
  Serial.print("Humidity: ");Serial.print(x);Serial.print("% Temp: ");Serial.print(y);Serial.println("°C");
  reading = analogRead(apin);
  Serial.println(reading);
   sensors.requestTemperatures();
  float temperatureC = sensors.getTempCByIndex(0);
  Serial.print("Temp DSB18: ");
  Serial.print(temperatureC);
  Serial.print("°C   ");
  Serial.print("sending -> ");
  ubidots.add("MyTemP", y);  // Change for your variable name
  ubidots.add("MyHumd", x);
  ubidots.add("DSB18", temperatureC);
ubidots.add("Analog", reading );
  bool bufferSent = false;
  bufferSent = ubidots.send();  // Will send data to a device label that matches the device Id

  if (bufferSent) {
    // Do something if values were sent properly
    Serial.println("Values sent by the device");
  }

  delay(5000);
}
