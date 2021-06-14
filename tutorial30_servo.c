#include <Servo.h> // get the servo library

int servoPin = 9;
int servoPos = 180; // degree
int dt = 50;

// create a Servo object
Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
}

void loop() {
  // get from the user
  Serial.println("what angle for the servo?");
  while(Serial.available() == 0){
  }
  servoPos = Serial.parseInt();
  myServo.write(servoPos);
  
}