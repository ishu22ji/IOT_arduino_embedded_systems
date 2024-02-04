void setup() {
    pinMode(D0, OUTPUT);
}

void loop() 
{
  //delay(2000);
  //float x = dht.readHumidity();
  //float y = dht.readTemperature();
  //Serial.print("Humidity: ");    Serial.print(x);    Serial.print("%  Temperature: ");  Serial.print(y);   Serial.println("°C ");
    digitalWrite(D0, 1);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(D0, 0);    // turn the LED off by making the voltage LOW
  delay(100); 
}
