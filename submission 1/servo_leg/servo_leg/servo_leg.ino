/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/
/* r=rise, f=front, d=down */
#include <Servo.h>

Servo r1,r2,f1,f2,d1,d2;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  r1.attach(7);
  r2.attach(1);
  d1.attach(8);
  d2.attach(2);
  f1.attach(9);
  f2.attach(3);
  // attaches the servo on pin 9 to the servo object
}

void loop() {
   for (pos = 60; pos >= 0; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    f1.write(pos);
    f2.write(pos);// tell servo to go to position in variable 'pos'
    delay(20);                       // waits 15ms for the servo to reach the position
  }
  delay(500);
  for (pos = 0; pos <= 60; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    r1.write(pos);
    r2.write(pos);// tell servo to go to position in variable 'pos'
    delay(20);                       // waits 15ms for the servo to reach the position
  } 
  delay(500);
  for (pos = 0; pos <=60; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    d1.write(pos);
    d2.write(pos);// tell servo to go to position in variable 'pos'
    delay(20);                       // waits 15ms for the servo to reach the position
  } delay(500);
 
  if(pos=60){ // goes from 180 degrees to 0   
    d1.write(0);
    d2 .write(0);
    r1.write(0);
    r2.write(0);// tell servo to go to position in variable 'pos'
    delay(20);                       // waits 15ms for the servo to reach the position
  }
  delay(500);
  }
