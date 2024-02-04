#define IO_USERNAME  "ishinder"
#define IO_KEY       "aio_HHzw59mfHqhrssff2fkfMZQqeCUV"
#define WIFI_SSID "Ishu"
#define WIFI_PASS "1234567890"
#include "AdafruitIO_WiFi.h"
////////////////////////////////////
#include "DHT.h"
#define DHTPIN D1  
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);
////////////////////////////////////
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS D2  // Define the GPIO pin where the DS18B20 sensor is connected

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
//////////////////////////////////////////////////////////////////
#if defined(USE_AIRLIFT) || defined(ADAFRUIT_METRO_M4_AIRLIFT_LITE) ||         \
    defined(ADAFRUIT_PYPORTAL)
// Configure the pins used for the ESP32 connection
#if !defined(SPIWIFI_SS) // if the wifi definition isnt in the board variant
// Don't change the names of these #define's! they match the variant ones
#define SPIWIFI SPI
#define SPIWIFI_SS 10 // Chip select pin
#define NINA_ACK 9    // a.k.a BUSY or READY pin
#define NINA_RESETN 6 // Reset pin
#define NINA_GPIO0 -1 // Not connected
#endif
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS, SPIWIFI_SS,
                   NINA_ACK, NINA_RESETN, NINA_GPIO0, &SPIWIFI);
#else
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);
#endif
///////////////////////////////
/////////////////////////////////
#define apin A0
int reading = 0;
AdafruitIO_Feed *ana = io.feed("myanalog");
AdafruitIO_Feed *bana = io.feed("myvoltage");
AdafruitIO_Feed *hana = io.feed("myhumidity");
AdafruitIO_Feed *tana = io.feed("mytemp");
AdafruitIO_Feed *mana = io.feed("mytemp_DSB18_wala");
void setup() {
  Serial.begin(115200);
  while(! Serial);
  Serial.print("Connecting to Adafruit IO");
  ////////////////////////////////
  dht.begin();
  pinMode(D0, OUTPUT);
//////////////////////////////////////


  io.connect();
///////////////////
  while(io.status() < AIO_CONNECTED) {
    Serial.println(".-----");
  digitalWrite(D0, 1); delay(100);
  digitalWrite(D0, 0); delay(200); 
  digitalWrite(D0, 1); delay(100);
  digitalWrite(D0, 0); delay(200); 
  digitalWrite(D0, 1); delay(100);
  digitalWrite(D0, 0); delay(200); 
  delay(100);
  }

  Serial.println();
  Serial.println("@@@@@@@@@@@@@@@@@@@@@@@");
  Serial.println(io.statusText());
  Serial.println("Node adafruit se connect ho gaya.-----");
  digitalWrite(D0, 1); delay(100);
  digitalWrite(D0, 0); delay(200); 
  digitalWrite(D0, 1); delay(100);
  digitalWrite(D0, 0); delay(400); 
  digitalWrite(D0, 1); delay(100); 
  digitalWrite(D0, 0); delay(400);
  digitalWrite(D0, 1); delay(200);
  digitalWrite(D0, 0); delay(400); 
  digitalWrite(D0, 1); delay(200);
  digitalWrite(D0, 0); delay(400); 
  digitalWrite(D0, 1); delay(200);
  digitalWrite(D0, 0); delay(400); 

}

void loop() {
  io.run();
  delay(2000);
  float x = dht.readHumidity();
  float y = dht.readTemperature();
  Serial.print("Humidity: ");Serial.print(x);Serial.print("% Temp: ");Serial.print(y);Serial.println("°C");
  reading = analogRead(apin);
   sensors.requestTemperatures();
  float temperatureC = sensors.getTempCByIndex(0);
  Serial.print("Temp DSB18: ");
  Serial.print(temperatureC);
  Serial.print("°C   ");
  Serial.print("sending -> ");
  float voltage=reading*3.223;  // 3300/1024
  ana->save(reading);
  bana->save(voltage);
  hana->save(x);
  tana->save(y);
   mana->save(temperatureC);
  Serial.println(reading);
  Serial.println(voltage);
  digitalWrite(D0, 1); delay(100);
  digitalWrite(D0, 0); delay(300); 
  digitalWrite(D0, 1); delay(500);
  digitalWrite(D0, 0); delay(300); 
  digitalWrite(D0, 1); delay(100); 
  digitalWrite(D0, 0); delay(300);
  Serial.print("----------------------------");
  Serial.print("----------------------------");
  delay(10000);
}
