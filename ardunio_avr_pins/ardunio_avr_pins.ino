

int timer = 200;           // The higher the number, the slower the timing.
int ledPins[] = { 0,1,2,3,4,6,7,8,9,10,11,12,13};       // an array of pin numbers to which LEDs are attached
int pinCount = 14;           // the number of pins (i.e. the length of the array)

void setup() {
  // the array elements are numbered from 0 to (pinCount - 1).
  // use a for loop to initialize each pin as an output:
  for (int a = 0; a < pinCount; a++) {
    pinMode(ledPins[a], OUTPUT);
  }
}

void loop() {
  // loop from the lowest pin to the highest:
  for (int a = 0; a < pinCount; a++) {
    // turn the pin on:
    digitalWrite(ledPins[a], HIGH);
    delay(timer);
    // turn the pin off:
    digitalWrite(ledPins[a], LOW);

  }

  // loop from the highest pin to the lowest:
  for (int thisPin = pinCount - 1; thisPin >= 0; thisPin--) {
    // turn the pin on:
    digitalWrite(ledPins[thisPin], HIGH);
    delay(timer);
    // turn the pin off:
    digitalWrite(ledPins[thisPin], LOW);
  }
}
