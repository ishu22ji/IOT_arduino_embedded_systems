#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 8
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
#include <DHT.h>

#define DHTPIN 9     
#define DHTTYPE DHT11    
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  delay(1000);
  lcd.print("WELCOME TO");
  delay(2000);
  lcd.setCursor(0, 1);
  lcd.print("The Core Systems");
  delay(3000);
  lcd.clear();
  delay(1000);
}

void loop() {
  // Read temperature and humidity from the Dsb18 sensor
    float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  sensors.requestTemperatures();
  float temperatureC = sensors.getTempCByIndex(0);
  lcd.setCursor(0, 0);
  lcd.print("Tem:");
  lcd.print(temperatureC);
  lcd.print(" C");
  lcd.setCursor(0, 8);
    lcd.print("hum:");
  lcd.print(humidity);
  lcd.print("Tem2:");
  lcd.print(temperature);
   Serial.println(temperatureC);
  Serial.println(temperature);
  Serial.println( humidity);
    
  delay(2000);  // Update the display every 2 seconds
}
