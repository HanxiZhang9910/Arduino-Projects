#include <Servo.h> // get the servo library

int lightPin = A0;
int lightVal;
int servoPin = 9;
int servoPos = 180; // degree
int dt = 50;

// create a Servo object
Servo myServo;

void setup() {
  Serial.begin(9600);
  pinMode(lightPin, INPUT);
  myServo.attach(servoPin);
}

void loop() {
  // get from the user
  lightVal = analogRead(lightPin);
  Serial.print("light value: ");
  Serial.println(lightVal);
  
  myServo.write(lightVal / 6);
  
}