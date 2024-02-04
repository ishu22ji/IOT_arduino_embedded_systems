

#include "DHT.h"

#define DHTPIN D1  
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("our dht11 test");
  dht.begin();
}

void loop() 
{
  delay(2000);
  float x = dht.readHumidity();
  float y = dht.readTemperature();
  Serial.print("Humidity: ");    Serial.print(x);    Serial.print("%  Temperature: ");  Serial.print(y);   Serial.println("°C ");
}
