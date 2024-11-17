#include <Servo.h>
//#include <SoftwareSerial.h>

//SoftwareSerial Bluetooth(12,9);


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
boolean aStatus = LOW;
boolean attStatus = LOW;
int k = 0;
int a = 0;
int aa = 0;
int period = 1000;
unsigned long time_now = 0;

float distance;
long duration;
//int dataIn;
int m = 0;
int h = 0;
int t = 0;
int att = 0;
int speedV = 30;


void setup() {
Serial.begin(9600);

//  Bluetooth.begin(38400); // Default baud rate of the Bluetooth module
//  Bluetooth.setTimeout(1);
  delay(20);  


  s18.attach(39, 600, 2400);
  s17.attach(38, 600, 2400);
  s16.attach(37, 600, 2400);
}

void loop() {
  
  if (Serial.available() > 0) {
    int dataIn = Serial.read();  // Read the data
    Serial.println("data received");
    Serial.println(dataIn);
    Serial.println("_______#####____");
    if (dataIn == 2) {
      m = 2;
    }
    if (dataIn == 3) {
      m = 3;
    }
    if (dataIn == 4) {
      m = 4;
    }
    if (dataIn == 5) {
      m = 5;
    }
    if (dataIn == 10) {
      t = 10;
    }
    if (dataIn == 11) {
      h = 11;
    }
    if (dataIn >= 15) {
      speedV = dataIn;
    }
  }
  // Move forward
  if (m == 2) {
    moveLeg1();
//    moveLeg3();
//    moveLeg5();
//    if (l1status == HIGH) {
//      moveLeg2();
//      moveLeg4();
//      moveLeg6();
    }
  }




void moveLeg1() {
  // Swign phase - move leg though air - from initial to final position
  // Rise the leg
  Serial.println("moving leg 1");
  if (i1L1 <= 10) {
    s18.write(60 - i1L1 * 2);
    s17.write(90 - i1L1 * 3);
    i1L1++;
  }
  // Rotate the leg
  if (i2L1 <= 30) {
    s16.write(100 - i2L1);
    i2L1++;

  }
  // Move back to touch the ground
  if (i2L1 > 20 & i3L1 <= 10) {
    s18.write(40 + i3L1 * 2);
    s17.write(60 + i3L1 * 3);
    i3L1++;
  }
  // Stance phase - move leg while touching the ground
  // Rotate back to initial position
  if (i2L1 >= 30) {
    s16.write(70 + i4L1);
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
