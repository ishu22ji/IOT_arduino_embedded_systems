int inx = 0;         // incoming serial byte
void setup() {
  Serial.begin(2400); 
  pinMode(D0, OUTPUT);
   Serial.println(" "); 
      Serial.println(" "); 
   delay(2000);
  Serial.println("------------ishinder------------------------"); delay(2000);
  Serial.println("------------------------------------"); delay(2000);
  Serial.println("------------------------------------"); delay(2000);
  Serial.println("hi kiddan ki haal chal ");
  delay(2000);
}

void loop() {


   if (Serial.available() > 0) {
     inx = Serial.read();
   digitalWrite(D0, 1);
  delay(50);
  digitalWrite(D0, 0);
  delay(20);
  digitalWrite(D0, 1);
  delay(50);
  digitalWrite(D0, 0);
  delay(20); 
  digitalWrite(D0, 1);
 Serial.write(inx);
  //  Serial.println(" "); 

   }
   // send sensor values:
   

}
