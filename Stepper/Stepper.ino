/* Example sketch to control a stepper motor with TB6600 stepper motor driver 
   and Arduino without a library: number of revolutions, speed and direction. 
   More info: https://www.makerguides.com */

// Define stepper motor connections and steps per revolution:
#define dirPin 2
#define stepPin 3
#define stepsPerRevolution 200



void setup() {
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  Serial.begin(9600);

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

void loop() {
  // Set the spinning direction clockwise:
  /*digitalWrite(dirPin, HIGH);
  
  // Spin the stepper motor 1 revolution slowly:
  /*for (int i=0; i < stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(2000);
  }

  delay(1000);

  // Set the spinning direction counterclockwise:
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
    Serial.print("\nAngle = "); 
    Serial.print(degree); 
    Serial.print(" degree, Light Intensity ="); 
    Serial.print(sensorValue);
    //Serial.println(degree);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(2000);
  }

  delay(10000);*/
}

  