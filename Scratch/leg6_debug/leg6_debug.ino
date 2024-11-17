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
  leg6_in.attach(24);
  leg6_mid.attach(23);
  leg6_out.attach(22);
  
  
  leg6_in.write(00);
  leg6_mid.write(60);
  leg6_out.write(120);


}

void loop() {
  // put your main code here, to run repeatedly:
  moveLeg6();
  delay(100);
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
  }

}
