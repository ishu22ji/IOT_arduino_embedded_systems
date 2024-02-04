#include "LedControl.h"
#include "DHT.h"

LedControl lc = LedControl(12, 11, 10, 1);
DHT dht(2, DHT11);
unsigned long delayTime = 2000;

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
  Serial.begin(9600);
}

void displayValue(int digit1, int digit2) {
  lc.setDigit(0, 3, digit1 / 10, false); // Tens digit
  lc.setDigit(0, 2, digit1 % 10, false); // Ones digit
  lc.setDigit(0, 1, digit2 / 10, false); // Tens digit
  lc.setDigit(0, 0, digit2 % 10, false); // Ones digit
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (!isnan(temperature) && !isnan(humidity)) {
    int tempInt = int(temperature);
    int humidityInt = int(humidity);
    displayValue(tempInt, humidityInt);
  } else {
    lc.setChar(0, 3, 'E', false);
    lc.setChar(0, 2, 'r', false);
    lc.setChar(0, 1, ' ', false); // Clear the humidity display
    lc.setChar(0, 0, ' ', false);
  }

  delay(delayTime);
}
