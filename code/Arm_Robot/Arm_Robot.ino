#include <Servo.h>  //  Include the Servo library

// Define servo pins
#define servo1 9   // Controls up-down
#define servo2 8   // Controls left-right
#define servo3 7  // Controls forward-backward
#define servo4 6  // Controls the clamp

Servo mservo1, mservo2, mservo3, mservo4;  // Create servo objects

int srv1 = 100; // Initial servo1 position
int srv2 = 0; // Initial servo2 position
int srv3 = 80;  // Initial servo3 position
int srv4 = 0; // Initial servo4 position

char Incoming_value = 0;  // variable for incoming serial value
char usechar = '0';         

void setup() {  
  Serial.begin(9600); // Start serial communication at 9600 bps

  mservo1.attach(servo1); // attaches the servo on pin 9 to the servo object
  mservo2.attach(servo2); // attaches the servo on pin 8 to the servo object
  mservo3.attach(servo3); // attaches the servo on pin 7 to the servo object
  mservo4.attach(servo4); // attaches the servo on pin 6 to the servo object
  // Set default positions on startup
  mservo1.write(srv1);     
  mservo2.write(srv2); 
  mservo3.write(srv3); 
  mservo4.write(srv4); 
}

void loop() {
  // Receive data from serial port
  if (Serial.available() > 0) {
    Incoming_value = Serial.read(); // Read the incoming byte
    usechar = Incoming_value; // Store the incoming byte in a variable
  }
  // Control servo 1 (base) up down
  if (usechar == 'A' && srv1 < 150) {
    srv1++;
    mservo1.write(srv1);
    delay(10);
  }
  // Control servo 1 (base) down
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
