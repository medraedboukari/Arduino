#include <Servo.h>

Servo myServo;  // Create a Servo object to control the servo motor

void setup() {
  myServo.attach(9);  // Attach the servo motor to PWM pin 9
}

void loop() {
  for (int pos = 0; pos <= 180; pos += 1) { // Goes from 0 to 180 degrees
    myServo.write(pos);  // Tell servo to go to position in variable 'pos'
    delay(15);           // Wait 15ms for the servo to reach the position
  }
  delay(1000);  // Wait 1 second

  for (int pos = 180; pos >= 0; pos -= 1) { // Goes from 180 to 0 degrees
    myServo.write(pos);  // Tell servo to go to position in variable 'pos'
    delay(15);           // Wait 15ms for the servo to reach the position
  }
  delay(1000);  // Wait 1 second
}
