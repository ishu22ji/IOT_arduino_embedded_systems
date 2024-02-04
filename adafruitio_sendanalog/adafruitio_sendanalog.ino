
// or ethernet clients.
#include "config.h"

/************************ Example Starts Here *******************************/

// analog pin 0
#define PHOTOCELL_PIN A0

// photocell state
int current = 0;
int last = -1;

// set up the 'analog' feed
AdafruitIO_Feed *ana = io.feed("myanalog");
AdafruitIO_Feed *bana = io.feed("myvoltage");
void setup() {

  // start the serial connection
  Serial.begin(115200);

  // wait for serial monitor to open
  while(! Serial);

  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());

}

void loop() {

  // io.run(); is required for all sketches.
  // it should always be present at the top of your loop
  // function. it keeps the client connected to
  // io.adafruit.com, and processes any incoming data.
  io.run();

  // grab the current state of the photocell
  current = analogRead(PHOTOCELL_PIN);

  // return if the value hasn't changed
  if(current == last)
    return;

  // save the current state to the analog feed
  Serial.print("sending -> ");
  Serial.println(current);
  float voltage=current*3.222;
  ana->save(current);
  bana->save(voltage);
  // store last photocell state
  last = current;

  // wait three seconds (1000 milliseconds == 1 second)
  //
  // because there are no active subscriptions, we can use delay()
  // instead of tracking millis()
  delay(6000);
}
