#include <Servo.h>


Servo s18;
Servo s17;
Servo s16;

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

int dataIn;
int m = 0;
int h = 0;
int t = 0;
int att = 0;
int speedV = 30;


void setup() {
  Serial.begin(38400);
  delay(20);
  s18.attach(39, 600, 2400);
  s17.attach(38, 600, 2400);
  s16.attach(37, 600, 2400);
  
  s18.write(180);
  s17.write(120);
  s16.write(90);

  delay(300);
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available() > 0) {
    dataIn = Serial.read();  // Read the data
    if (dataIn == 2) {
      m = 2;
      Serial.println("got info...moving forward   ");
    }
    if (dataIn == 3) {
      m = 3;
      Serial.println("got info...rotating left   ");
    }
    if (dataIn == 4) {
      m = 4;
      Serial.println("got info...rotating right   ");
    }
    if (dataIn == 5) {
      m = 5;
      Serial.println("got info...moving reverse   ");
    }
    if (dataIn == 10) {
      t = 10;
      Serial.println("got info...dataIn or t =10   ");
    }
    if (dataIn == 11) {
      h = 11;
      Serial.println("got info...dataIn or h=11  ");
    }
    if (dataIn >= 15) {
      speedV = dataIn;
      Serial.println("got info...data in greater than 15   ");
      Serial.print(speedV);
    }
  }

  moveLeg1();
//  delay(speedV);
}



void moveLeg1() {
  // Swign phase - move leg though air - from initial to final position
  // Rise the leg
  if (i1L1 <= 10) {
    s18.write(180 - i1L1 * 2);
    s17.write(120 - i1L1 * 3);
    i1L1++;
  }
  // Rotate the leg
  if (i2L1 <= 30) {
    s16.write(90 - i2L1);
    i2L1++;

  }
  // Move back to touch the ground
  if (i2L1 > 20 & i3L1 <= 10) {
    s18.write(160 + i3L1 * 2);
    s17.write(90 + i3L1 * 3);
    i3L1++;
  }
  // Stance phase - move leg while touching the ground
  // Rotate back to initial position
  if (i2L1 >= 30) {
    s16.write(60 + i4L1);
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
