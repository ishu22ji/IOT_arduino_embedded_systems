#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS D2  // Define the GPIO pin where the DS18B20 sensor is connected

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures();
  float temperatureC = sensors.getTempCByIndex(0);
  
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print("°C   ");

  delay(1000);  // Read temperature every 1 second
}
