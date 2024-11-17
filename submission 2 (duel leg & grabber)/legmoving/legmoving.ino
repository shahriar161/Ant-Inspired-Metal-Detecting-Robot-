
#include <Servo.h>

Servo body1,link1,leg1,body2,link2,leg2;  

int pos = 0;    

void setup() {
  body1.attach(11);
  link1.attach(9);
  leg1.attach(10);  
  body2.attach(3);
  link2.attach(5);
  leg2.attach(6);  
}

void loop() {
  for (pos = 0; pos <= 90; pos += 1) { 
    body1.write(pos);
    link1.write(pos);
    leg1.write(pos);
   delay(15);                       
  }delay(500);
  
   for (pos = 0; pos <= 90; pos += 1) { 
     body2.write(pos);
     link2.write(pos);
     leg2.write(pos);
     delay(15);                       
  }delay(500);
  
  for (pos = 90; pos >= 0; pos -= 1) { 
    body1.write(pos);  
    link1.write(pos);
    leg1.write(pos);            
    delay(15);                       
  }delay(500);
  
    for (pos = 90; pos <= 0; pos -= 1) { 
    body2.write(pos);
    link2.write(pos);
    leg2.write(pos);
   delay(15);                       
  }delay(500);
}
