#include <Servo.h>

Servo servo;  // create servo object to control a servo

const int inc_rad = 10;
const int dec_rad = 11;
const int scan = 7;

#define dirPin 2
#define stepPin 3
#define stepsPerRevolution 200


void setup() {
  servo.attach(9);  // attaches the servo on pin 9 to the servo objectư
  pinMode(inc_rad,INPUT_PULLUP);
  pinMode(dec_rad,INPUT_PULLUP);
  pinMode(scan,INPUT_PULLUP);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(scan)==LOW){              //starting one full scan

    digitalWrite(dirPin, HIGH);

    // Spin the stepper motor 1 revolution quickly:
    
    for (int i=0; i < stepsPerRevolution; i++) {
      // These four lines result in 1 step:
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(2000);
      int  sensorValue1 = analogRead(A0);
      int sensorValue2 = analogRead(A1);
      int sensorValue = (sensorValue1+sensorValue2)/2;
      float degree = map(i,0,199,0,360);
      //Serial.print("\nAngle = "); 
      Serial.println(degree); 
      //Serial.print(" degree, Light Intensity ="); 
      Serial.println(sensorValue);
      //Serial.println(degree);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(2000);
    }

    delay(2000);

    digitalWrite(dirPin, LOW);

    // Spin the stepper motor 1 revolution quickly:
    
    for (int i=0; i < stepsPerRevolution; i++) {
      // These four lines result in 1 step:
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(2000);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(2000);
    }
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