
#include <Servo.h>

Servo leg11,leg12,leg13,;
int pos = 0;    // variable to store the servo position

void setup() {
  leg11.attach(9);
  leg12.attach(10);
  leg13.attach(11);
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { 
    leg11.write(pos);
    delay(5);
  }
  
  for (pos = 0; pos <= 180; pos += 1) { 
    leg12.write(pos);
    delay(5);
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    leg11.write(pos);
    leg12.write(pos);              
    delay(5);                       
  }
  delay(500);
}
