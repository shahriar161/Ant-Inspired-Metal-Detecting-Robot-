#include <Servo.h>
Servo leg1_in,leg1_mid,leg1_out,leg2_in,leg2_mid,leg2_out;
Servo leg3_in,leg3_mid,leg3_out,leg4_in,leg4_mid,leg4_out,leg5_in,leg5_mid,leg5_out,leg6_in,leg6_mid,leg6_out;
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
boolean l1status=LOW;

void setup() {
  leg1_in.attach(37);
  leg1_mid.attach(38);
  leg1_out.attach(39);
  
  leg2_in.attach(40);
  leg2_mid.attach(41);
  leg2_out.attach(42);

  
  leg3_in.attach(43);
  leg3_mid.attach(44);
  leg3_out.attach(45);

  leg4_in.attach(33);
  leg4_mid.attach(32);
  leg4_out.attach(31);
  
  leg5_in.attach(30);
  leg5_mid.attach(29);
  leg5_out.attach(28);

  
  leg6_in.attach(24);
  leg6_mid.attach(23);
  leg6_out.attach(22);
  

//#########################
  leg1_in.write(110);
  leg1_mid.write(100);
  leg1_out.write(180);
  
  leg2_in.write(90);
  leg2_mid.write(40);
  leg2_out.write(0);

  leg3_in.write(40);
  leg3_mid.write(0);
  leg3_out.write(40);
  
  leg4_in.write(60);
  leg4_mid.write(60);
  leg4_out.write(40);
  
  leg5_in.write(30);
  leg5_mid.write(90);
  leg5_out.write(60);

  
  leg6_in.write(00);
  leg6_mid.write(60);
  leg6_out.write(120);


}

void loop() {
  moveLeg1();  
//  delay(100);
  moveLeg3();
//  delay(100);
  moveLeg5();  
//  delay(100);
  moveLeg2();
//  delay(100);
//  moveLeg4();  
//  delay(100);
  moveLeg6();
  delay(200);
}

void moveLeg1() {
  // Swign phase - move leg though air - from initial to final position
  // Rise the leg
  if (i1L1 <= 10) {
    leg1_out.write(180 - i1L1 * 2);
    leg1_mid.write(100 - i1L1 * 3);
    i1L1++;
  }
  // Rotate the leg
  if (i2L1 <= 30) {
    leg1_in.write(10+100 - i2L1);
    i2L1++;

  }
  // Move back to touch the ground
  if (i2L1 > 20 & i3L1 <= 10) {
    leg1_out.write(180 + i3L1 * 2);
    leg1_mid.write(100 + i3L1 * 3);
    i3L1++;
  }
  // Stance phase - move leg while touching the ground
  // Rotate back to initial position
  if (i2L1 >= 30) {
    leg1_in.write(110+ i4L1);
    i4L1++;
    l1status = HIGH;
  }
  // Reset the counters for repeating the process
  if (i4L1 >= 30) {
    i1L1 = 0;
    i2L1 = 0;
    i3L1 = 0;
    i4L1 = 0;
    i5L1 = 0;
  }
  // Each iteration or step is executed in the main loop section where there is also a delay time for controlling the speed of movement
}
void moveLeg2() {
  if (i1L2 <= 10) {
    leg6_mid.write(-50+50 - i1L2 * 2);
    leg2_mid.write(-40+80 - i1L2 * 3);
    i1L2++;
  }
  if (i2L2 <= 30) {
    leg2_in.write(15+75 - i2L2);
    i2L2++;

  }
  if (i2L2 > 20 & i3L2 <= 10) {
    leg6_mid.write(-50+30 + i3L2 * 2);
    leg2_mid.write(-40+50 + i3L2 * 3);
    i3L2++;
  }
  if (i2L2 >= 30) {
    leg2_in.write(15+45 + i4L2);
    i4L2++;
  }
  if (i4L2 >= 30) {
    i1L2 = 0;
    i2L2 = 0;
    i3L2 = 0;
    i4L2 = 0;
    i5L2 = 0;
  }
}

void moveLeg3() {
  if (i1L1 <= 10) {
    leg6_mid.write(10+50 - i1L1 * 2);
    leg3_mid.write(-80+80 - i1L1 * 3);
  }
  if (i2L1 <= 30) {
    leg3_in.write(-20+80 - i2L1);

  }
  if (i2L1 > 20 & i3L1 <= 10) {
    leg6_mid.write(10+30 + i3L1 * 2);
    leg3_mid.write(-80+50 + i3L1 * 3);
  }
  if (i2L1 >= 30) {
    leg3_in.write(-20+50 + i4L1);
  }
}

void moveLeg4() {
  if (i1L2 <= 10) {
    leg4_out.write(-25+65 + i1L2 * 2);
    leg4_mid.write(25+35 + i1L2 * 3);
  }
  if (i2L2 <= 30) {
    leg4_in.write(20+35 + i2L2);

  }
  if (i2L2 > 20 & i3L2 <= 10) {
    leg4_out.write(-25+85 - i3L2 * 2);
    leg4_mid.write(25+65 - i3L2 * 3);
  }
  if (i2L2 >= 30) {
    leg4_in.write(20+65 - i4L2);
  }
}

void moveLeg5() {
  if (i1L1 <= 10) {
    leg5_out.write(-20+80 + i1L1 * 2);
    leg5_mid.write(40+50 + i1L1 * 3);
    i1L1++;
  }
  if (i2L1 <= 30) {
    leg5_in.write(5+30 + i2L1);
  i2L1++;
  }
  if (i2L1 > 20 & i3L1 <= 10) {
    leg5_out.write(-20+100 - i3L1 * 2);
    leg5_mid.write(40+80 - i3L1 * 3);
  i3L1++;
  }
  if (i2L1 >= 30) {
    leg5_in.write(5+60 - i4L1);
  }
}

void moveLeg6() {
  if (i1L2 <= 10) {
    leg6_out.write(30+90 + i1L2 * 2);
    leg6_mid.write(15+45 - i1L2 * 3);
    i1L2++;}
  if (i2L2 <= 30) {
    leg6_in.write(0 + i2L2);
    i2L2++;
  }
  if (i2L2 > 20 & i3L2 <= 10) {
    leg6_out.write(30+110 - i3L2 * 2);
    leg6_mid.write(15+75 - i3L2 * 3);
    i3L2++;
  }
  if (i2L2 >= 30) {
    leg6_in.write(-60+90 - i4L2);
    i4L2++;
//    l2status =HIGH;
  }
if (i4L1 >= 30) {
    i1L1 = 0;
    i2L1 = 0;
    i3L1 = 0;
    i4L1 = 0;
    i5L1 = 0;
}  }
