/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
char Incoming_value = 0;

Servo inservo1,midservo1,outservo1;
Servo inservo2,midservo2,outservo2;
Servo inservo4,midservo4,outservo4;
Servo inservo3,midservo3,outservo3;  
Servo inservo6,midservo6,outservo6;
Servo inservo5,midservo5,outservo5;  
int pos = 0;    // variable to store the servo position

void setup() {
    inservo1.attach(37);
    midservo1.attach(38);
    outservo1.attach(39);
//  
    inservo2.attach(40);
    midservo2.attach(41);
    outservo2.attach(42);
    
    inservo4.attach(33);
    midservo4.attach(32);
    outservo4.attach(31);
    inservo3.attach(43);
    midservo3.attach(44);
    outservo3.attach(45);
  inservo5.attach(30);
  midservo5.attach(29);
  outservo5.attach(28);
  inservo6.attach(24);
  midservo6.attach(23);
  outservo6.attach(22);
  Serial.begin(9600);
pinMode(10,OUTPUT);
}

void loop() {
  outservo1.write(180);
  midservo1.write(105);
  inservo1.write(105);
  
  outservo2.write(0);
  midservo2.write(75);
  inservo2.write(75);

  
  outservo4.write(70);
  midservo4.write(90);
  inservo4.write(90);
  
  outservo3.write(30);
  midservo3.write(120);
  inservo3.write(45);
  outservo5.write(30);
  midservo5.write(60);
  inservo5.write(90);
  outservo6.write(120);
  midservo6.write(60);
  inservo6.write(90);

  blue();
  
//  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    inservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }delay(1000);
//  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
//    inservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }
  
}
void blue(){
  if (Serial.available() > 0)
    {
      Incoming_value = Serial.read();
      Serial.print(Incoming_value);
      Serial.print("/n");
      if (Incoming_value == '1')
        digitalWrite(10,HIGH);
      else if(Incoming_value == '0')
        digitalWrite(10,LOW);
        
    }
}
