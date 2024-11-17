#include <Servo.h>

Servo inservo1,midservo1,outservo1;
Servo inservo2,midservo2,outservo2;
Servo inservo4,midservo4,outservo4;
Servo inservo3,midservo3,outservo3;  
Servo inservo6,midservo6,outservo6;
Servo inservo5,midservo5,outservo5;  

int i0H1 = 0;
int i1H1 = 0;
int i2H1 = 0;
int i3H1 = 0;
int i4H1 = 0;
int i5H1 = 0;
int i6H1 = 0;
int i7H1 = 0;
int i8H1 = 0;

int i0T1 = 0;
int i1T1 = 0;
int i2T1 = 0;
int i3T1 = 0;
int i4T1 = 0;
int i5T1 = 0;
int i6T1 = 0;

int i1L1 = 0;
int i2L1 = 0;
int i3L1 = 0;
int i4L1 = 0;
int i5L1 = 0;
int i6L1 = 0;

int i1L2 = 0;
int i2L2 = 0;
int i3L2 = 0;
int i4L2 = 0;
int i5L2 = 0;
int i6L2 = 0;
boolean l1status = LOW;
boolean l2status = LOW;
boolean aStatus = LOW;
boolean attStatus = LOW;
int i;
void setup() {
  inservo1.attach(37);
  midservo1.attach(38);
  outservo1.attach(39);
  inservo2.attach(40);
  midservo2.attach(41);
  outservo2.attach(42);
  inservo4.attach(35);
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

  initialpos();
  delay(3000);
}

void loop() {
////  moveLeg1();
  
  forward();
  initialpos();
  
//  outservo.write(105+25);
//  while(HIGH){}
}

void moveLeg1() {
  for(i=0;i<=25;i++){
    outservo1.write(180-i);
    delay(7);
  }
  for(i=0;i<=25;i++){
    midservo1.write(105+i);
    delay(7);
  }
  for(i=0;i<=40;i++){
    inservo1.write(105+i);
    delay(7);
  }

//out
  for(i=0;i<=25;i++){
    outservo1.write(165+i);
    delay(7);
  }
//  mid
  for(i=0;i<=25;i++){
    midservo1.write(130-i);
    delay(7);
  }
}

void moveLeg1init(){
  for(i=0;i<=40;i++){
    inservo1.write(145-i);
    delay(7);
  }
}

void moveLeg2(){
  for(i=0;i<=25;i++){
    outservo2.write(30+i);
    delay(7);
  }
  for(i=0;i<=25;i++){
    midservo2.write(60-i);
    delay(7);
  }
  for(i=0;i<=40;i++){
    inservo2.write(90-i);
    delay(7);
  }
 
//out
  for(i=0;i<=55;i++){
    outservo2.write(55-i);
    delay(7);
  }
//  in
  for(i=0;i<=25;i++){
    midservo2.write(35+i);
    delay(7);
  }
}

void moveLeg2init(){
  for(i=0;i<=40;i++){
    inservo2.write(50+i);
    delay(7);
  }
}

void moveLeg3(){
  for(i=0;i<=25;i++){
    outservo3.write(30-i);
    delay(7);
  }
  for(i=0;i<=25;i++){
    midservo3.write(120+i);
    delay(7);
  }
  for(i=0;i<=25;i++){
    inservo3.write(45+i);
    delay(7);
  }
  
//out
  for(i=0;i<=25;i++){
    outservo3.write(5+i);
    delay(7);
  }
//  in
  for(i=0;i<=25;i++){
    midservo3.write(145-i);
    delay(7);
  }
}

void moveLeg3init(){
  for(i=0;i<=25;i++){
    inservo3.write(70-i);
    delay(7);
  }
}
 void moveLeg4(){
   for(i=0;i<=25;i++){
     outservo4.write(70-i);
     delay(7);
   }
    for(i=0;i<=25;i++){
      midservo4.write(90+i);
      delay(7);
    }
   for(i=0;i<=25;i++){
     inservo4.write(90-i);
     delay(7);
   }
 
// out
   for(i=0;i<=25;i++){
     outservo4.write(45+i);
     delay(7);
   }
 //  in
    for(i=0;i<=35;i++){
      midservo4.write(115-i);
      delay(7);
    }
 }

 void moveLeg4init(){
   for(i=0;i<=25;i++){
     inservo4.write(65+i);
     delay(7);
   }
 }
void moveLeg5() {
  for(i=0;i<=25;i++){
    outservo5.write(10+i);
    delay(3);
  }
  for(i=0;i<=25;i++){
    midservo5.write(60-i);
    delay(3);
  }
  for(i=0;i<=20;i++){
    inservo5.write(60+i);
    delay(3);
  }
 
//out
  for(i=0;i<=25;i++){
    outservo5.write(35-i);
    delay(3);
  }
//  in
  for(i=0;i<=25;i++){
    midservo5.write(35+i);
    delay(3);
  }
}

void moveLeg5init(){
  for(i=0;i<=20;i++){
    inservo5.write(80-i);
    delay(3);
  } 
 delay(1000);
}
void moveLeg6(){
  for(i=0;i<=25;i++){
    outservo6.write(120-i);
    delay(3);
  }
  for(i=0;i<=25;i++){
    midservo6.write(60+i);
    delay(3);
  }
  for(i=0;i<=30;i++){
    inservo6.write(120-i);
    delay(3);
  }

//out
  for(i=0;i<=25;i++){
    outservo6.write(95+i);
    delay(3);
  }
//  in
  for(i=0;i<=25;i++){
    midservo6.write(85-i);
    delay(3);
  }
}

void moveLeg6init(){
  for(i=0;i<=30;i++){
    inservo6.write(90+i);
    delay(3);
  }
  delay(1000);
}
void initialpos(){
  outservo1.write(180);
  midservo1.write(105);
  inservo1.write(105); 
  outservo2.write(0);
  midservo2.write(75);
  inservo2.write(75); 
  outservo4.write(70);
  midservo4.write(90);
  inservo4.write(90);           
//  ----------------------------------------------------------------------------------------------------------------------5555555555555
  outservo3.write(30);
  midservo3.write(120);
  inservo3.write(45);
  outservo5.write(10);
  midservo5.write(60);
  inservo5.write(60);
  outservo6.write(120);
  midservo6.write(60);
  inservo6.write(120);
}

void forward(){
  moveLeg1();
  moveLeg2();
  
   
  moveLeg5();
  moveLeg6();
  moveLeg3();  
  moveLeg4();
  
  moveLeg1init();
  moveLeg2init();
  
  
  moveLeg5init();
  moveLeg6init();
  moveLeg3init();
  moveLeg4init();
  
}

// void bluetooth(){
//   if (Serial.available() > 0)
//     {
//       Incoming_value = Serial.read();
//       Serial.print(Incoming_value);
//       Serial.print("/n");
//       if (Incoming_value == '1')
//         digitalWrite(10,HIGH);
//       else if(Incoming_value == '0')
//         digitalWrite(10,LOW);
        
//     }
// }
