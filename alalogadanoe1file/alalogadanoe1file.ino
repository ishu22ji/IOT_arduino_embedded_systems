#define IO_USERNAME  "ishinder"
#define IO_KEY       "aio_HHzw59mfHqhrssff2fkfMZQqeCUV"
#define WIFI_SSID "R1x"
#define WIFI_PASS "123456789"
#include "AdafruitIO_WiFi.h"
////////////////////////////////////
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
void setup() {
  Serial.begin(115200);
  while(! Serial);
  Serial.print("Connecting to Adafruit IO");
  io.connect();
///////////////////
  while(io.status() < AIO_CONNECTED) {
    Serial.println(".-----");
    delay(500);
  }

  Serial.println();
  Serial.println("@@@@@@@@@@@@@@@@@@@@@@@");
  Serial.println(io.statusText());
  Serial.println("Node adafruit se connect ho gaya.-----");
  delay(500);
  delay(500);

}

void loop() {
  io.run();
  reading = analogRead(apin);
  Serial.print("sending -> ");
  float voltage=reading*3.223;  // 3300/1024
  ana->save(reading);
  bana->save(voltage);
  Serial.println(reading);
  Serial.println(voltage);
  Serial.print("----------------------------");
  Serial.print("----------------------------");
  delay(6000);
}
