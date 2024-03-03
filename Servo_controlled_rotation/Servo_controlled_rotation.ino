#include <Servo.h>

Servo servo;  // create servo object to control a servo

void setup() {
  servo.attach(9);  // attaches the servo on pin 9 to the servo objectư
}

void loop() {
  servo.write(180);   // to rotate counter-clockwise
  delay(300);
  servo.write(90);  // to stop
  delay(1000);
  servo.write(0);  // to rotate clockwise
  delay(300);
  servo.write(90);
  delay(1000);
}