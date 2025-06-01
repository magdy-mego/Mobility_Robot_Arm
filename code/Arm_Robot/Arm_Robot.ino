#include <Servo.h>  //  Include the Servo library

// Define servo pins
#define servo1 9   // Controls up-down
#define servo2 8   // Controls left-right
#define servo3 7  // Controls forward-backward
#define servo4 6  // Controls the clamp

Servo mservo1, mservo2, mservo3, mservo4;  

int srv1 = 100;
int srv2 = 0;
int srv3 = 80;
int srv4 = 0;

char Incoming_value = 0; 
char usechar = '0';      

void setup() {
  Serial.begin(9600);  
  mservo1.attach(servo1); 
  mservo2.attach(servo2); 
  mservo3.attach(servo3); 
  mservo4.attach(servo4); 

  mservo1.write(srv1); 
  mservo2.write(srv2); 
  mservo3.write(srv3); 
  mservo4.write(srv4); 
}

void loop() {
  if (Serial.available() > 0) {
    Incoming_value = Serial.read();
    usechar = Incoming_value;  
  }

  if (usechar == 'A' && srv1 < 150) {
    srv1++;
    mservo1.write(srv1);
    delay(10);
  }

  if (usechar == 'B' && srv1 > 50) {
    srv1--;
    mservo1.write(srv1);
    delay(10);
  }

  if (usechar == 'C' && srv2 < 180) {
    srv2++;
    mservo2.write(srv2);
    delay(10);
  }

  if (usechar == 'D' && srv2 > 0) {
    srv2--;
    mservo2.write(srv2);
    delay(10);
  }

  if (usechar == 'G' && srv3 < 120) {
    srv3++;
    mservo3.write(srv3);
    delay(10);
  }

  if (usechar == 'J' && srv3 > 40) {
    srv3--;
    mservo3.write(srv3);
    delay(10);
  }

  if (usechar == 'F' && srv4 < 35) {
    srv4++;
    mservo4.write(srv4);
    delay(10);
  }

  if (usechar == 'I' && srv4 > 0) {
    srv4--;
    mservo4.write(srv4);
    delay(10);
  }
}
