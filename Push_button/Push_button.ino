#include <Servo.h>

Servo servo;  // create servo object to control a servo

const int inc_rad = 10;
const int dec_rad = 11;
const int scan = 12;


void setup() {
  servo.attach(9);  // attaches the servo on pin 9 to the servo objectư
  pinMode(inc_rad,INPUT_PULLUP);
  pinMode(dec_rad,INPUT_PULLUP);
  pinMode(scan,INPUT_PULLUP);
}

void loop() {
  if(scan==LOW){              //starting one full scan

  }

  if(digitalRead(inc_rad)==LOW){
    servo.write(180);
    delay(100);
    servo.write(90);
    //delay(500);
  }

  if(digitalRead(dec_rad)==LOW){
    servo.write(0);
    delay(100);
    servo.write(90);
    //delay(500);
  }

}