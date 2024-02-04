
#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);

void setup() {
 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.clear();
  delay(1000);
  lcd.print("WELCOME TO");
    delay(2000);
    lcd.setCursor(0,1); 
    lcd.print("The Core Systems");
    delay(3000);
    lcd.clear();
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("V1:");
  lcd.setCursor(0,1);
   lcd.print("V2:");
   lcd.setCursor(8,0);
   lcd.print("V3:");
   lcd.setCursor(8,1);
   lcd.print("V4:");
    


}

void loop() {
   
   int analogA0 = analogRead(A0);
   int analogA1 = analogRead(A1);
   int analogA2 = analogRead(A2);
   int analogA3 = analogRead(A3);

   float voltageA0 = analogA0 * 4.887 / 1000;
   float voltageA1 = analogA1 * 4.887 / 1000;
   float voltageA2 = analogA2 * 4.887 / 1000;
   float voltageA3 = analogA3 * 4.887 / 1000;

   lcd.setCursor(3, 0);
   lcd.print(voltageA0);
   lcd.setCursor(3, 1);
   lcd.print(voltageA1);
   lcd.setCursor(11, 0);
   lcd.print(voltageA2);
   lcd.setCursor(11, 1);
   lcd.print(voltageA3);

   delay(1000);
}
