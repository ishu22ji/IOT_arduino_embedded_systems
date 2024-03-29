//RS-485 Modbus Slave (Arduino UNO)

//Circuit Digest


#include<ModbusRtu.h>       //Library for using Modbus in Arduino



#define led1 D0          //Define as 2 led1 

#define led2 D1             //Define as 5 led2

Modbus bus;                          //Define Object bus for class modbus 

uint16_t modbus_array[] = {0,0,0};    //Array initilized with three 0 values
                     

void setup()

{


  delay(5000);


  

  pinMode(led1,OUTPUT);           //Led1 set as OUTPUT

  pinMode(led2,OUTPUT);           //Led2 set as OUTPUT

  servo.attach(6);                //Servo PWM pin 6

  bus = Modbus(1,1,D2);            //Modbus slave ID as 1 and 1 connected via RS-485 and 4 connected to DE & RE pin of RS-485 Module 

  bus.begin(9600);                //Modbus slave baudrate at 9600

}


void loop()


{

   bus.poll(modbus_array,sizeof(modbus_array)/sizeof(modbus_array[0]));       //Used to receive or write value from Master 

  

  if (modbus_array[0] == 0)    //Depends upon value in modubus_array[0] written by Master Modbus

  {

    digitalWrite(led1,LOW);    //LED OFF if 0

    lcd.setCursor(0,0);

    lcd.print("L1:OFF");

  }

  else

  {

     digitalWrite(led1,HIGH);  //LED ON if value other than 0

     lcd.setCursor(0,0);

     lcd.print("L1:ON");        

  } 


 if (modbus_array[1] == 0)    //Depends upon value in modbus_array[1] written by Master Modbus

  {

    digitalWrite(led2,LOW);   //LED OFF if 0

    lcd.setCursor(8,0);

    lcd.print("L2:OFF");

  }

  else

  {

     digitalWrite(led2,HIGH);  //LED ON if value other than 0

     lcd.setCursor(9,0);

     lcd.print("L2:ON");

  }

  

  int pwm = modbus_array[2]; //Depends upon value in modbus_array[1] written by Master Modbus

 

  servo.write(pwm);          //Write Received value (0 to 180) from Modbus Master

  lcd.setCursor(0,1);        

  lcd.print("Servo angle:");

  lcd.print(pwm);              //Prints Angle in 16x2 LCD display.

  delay(200); 

  lcd.clear();

}
