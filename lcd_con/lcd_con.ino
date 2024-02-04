#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
char message[] = "Hello kese ho"; // Message to scroll

void setup() {
  lcd.begin(16, 2);
  lcd.print(message);
  delay(1000);
  lcd.clear();
}

void loop() {
  // Scroll the text
  for (int i = 0; i < (strlen(message) + 16); i++) {
    lcd.clear();
    lcd.setCursor(i, 0);
    int len = min(16, strlen(message) - i); // Length to print without exceeding screen width
    for (int j = 0; j < len; j++) {
      lcd.print(message[i + j]);
    }
    delay(300);
  }
}
