#include "UbidotsMicroESP8266.h"

#define TOKEN  "BBFF-6RNW5cSXxaGRdi0QHMChRR5Jir480u"  // Put here your Ubidots TOKEN
#define WIFISSID "Hloo" // Put here your Wi-Fi SSID
#define PASSWORD "1234567890" // Put here your Wi-Fi password

Ubidots client(TOKEN);

void setup(){
    Serial.begin(115200);
    client.wifiConnection(WIFISSID, PASSWORD);
}
void loop(){
    float value1 = analogRead(A0);
    client.add("ANALOGX", value1);
  
    client.sendAll(true);
    delay(5000);
}
