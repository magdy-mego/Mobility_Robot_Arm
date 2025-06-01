# Robotic Arm Project

## Overview
This repository contains the code and design files for a 4-servo robotic arm controlled via an Arduino Uno. The arm is designed to perform basic movements such as up-down, left-right, forward-back, and clamping actions, with control facilitated through a Bluetooth module (HC-05).

## Hardware Requirements
- Arduino Uno
- 4 Servos (labeled servo1, servo2, servo3, servo4)
- HC-05 Bluetooth Module
- Jumper wires
- Breadboard (optional)
- Power supply (compatible with Arduino and servos)

## Wiring
- **Servo1 (up-down)**: Connected to pin 9
- **Servo2 (rotation)**: Connected to pin 8
- **Servo3 (forward-back)**: Connected to pin 7
- **Servo4 (clamp)**: Connected to pin 6
- **HC-05 Bluetooth Module**:
  - VCC to 5V
  - GND to GND
  - TXD to pin 10
  - RXD to pin 11

Refer to the included wiring diagram image for a visual guide.

## Software Requirements
- Arduino IDE
- Installed Servo library (included by default in Arduino IDE)

## Installation
1. Clone this repository to your local machine.
2. Open the `Arm_Robot.ino` file in the Arduino IDE.
3. Connect your Arduino Uno to your computer via USB.
4. Select the correct board and port in the Arduino IDE.
5. Upload the sketch to your Arduino.

## Usage
- Pair the HC-05 Bluetooth module with a Bluetooth-enabled device (e.g., smartphone or computer).
- Use a serial terminal or a custom app to send the following commands:
  - `A`: Increase servo1 angle (up)
  - `B`: Decrease servo1 angle (down)
  - `C`: Increase servo2 angle (left)
  - `D`: Decrease servo2 angle (right)
  - `G`: Increase servo3 angle (forward)
  - `J`: Decrease servo3 angle (back)
  - `F`: Increase servo4 angle (clamp)
  - `I`: Decrease servo4 angle (release)
- The servos will move incrementally with a 10ms delay between adjustments.

## Design
The robotic arm design is detailed in the included diagram, with dimensions:
- Total length: 155.20 mm
- Arm width: 78.95 mm
- Height: 125.27 mm

## Contributing
Feel free to fork this repository, make improvements, and submit pull requests. Issues and feature requests are welcome!

## License
This project is open-source under the MIT License.

## Acknowledgments
- Thanks to the Arduino community for the robust platform.
- Special thanks to the creators of the HC-05 module for wireless control.