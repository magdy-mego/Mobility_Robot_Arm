#include <Servo.h>

// Define servo pins
#define SERVO1_PIN 9   // Controls up-down
#define SERVO2_PIN 8   // Controls left-right
#define SERVO3_PIN 7   // Controls forward-backward
#define SERVO4_PIN 6   // Controls the clamp

// Create Servo objects
Servo mservo1, mservo2, mservo3, mservo4;

// Initial servo positions
int pos1 = 100;
int pos2 = 0;
int pos3 = 80;
int pos4 = 0;

// Incoming character from serial
char incomingValue = 0;

void setup() {
  Serial.begin(9600); // Initialize serial communication

  // Attach servo objects to their respective pins
  mservo1.attach(SERVO1_PIN); 
  mservo2.attach(SERVO2_PIN);
  mservo3.attach(SERVO3_PIN);
  mservo4.attach(SERVO4_PIN);

  // Set initial positions
  mservo1.write(pos1);
  mservo2.write(pos2);
  mservo3.write(pos3);
  mservo4.write(pos4);
}

// Function to move a servo within a specified range
void moveServo(Servo &servo, int &pos, int delta, int minVal, int maxVal) {
  int newPos = pos + delta;
  if (newPos >= minVal && newPos <= maxVal) {
    pos = newPos;
    servo.write(pos);
    delay(10); // Small delay to allow movement
  }
}

void loop() {
  // Check for serial input
  if (Serial.available() > 0) {
    incomingValue = Serial.read();
  }

  // Handle servo movement based on received character
  switch (incomingValue) {
    case 'A': // Move servo1 up
      moveServo(mservo1, pos1, +1, 50, 150);
      break;
    case 'B': // Move servo1 down
      moveServo(mservo1, pos1, -1, 50, 150);
      break;
    case 'C': // Move servo2 right
      moveServo(mservo2, pos2, +1, 0, 180);
      break;
    case 'D': // Move servo2 left
      moveServo(mservo2, pos2, -1, 0, 180);
      break;
    case 'G': // Move servo3 forward
      moveServo(mservo3, pos3, +1, 40, 120);
      break;
    case 'J': // Move servo3 backward
      moveServo(mservo3, pos3, -1, 40, 120);
      break;
    case 'F': // Open clamp (servo4)
      moveServo(mservo4, pos4, +1, 0, 35);
      break;
    case 'I': // Close clamp (servo4)
      moveServo(mservo4, pos4, -1, 0, 35);
      break;
    default:
      break; // Ignore any other input
  }
}
