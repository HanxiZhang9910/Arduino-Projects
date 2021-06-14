#include<Servo.h>

int lightVal;
int lightPin = A0;
int servoPin = 9;
int dt = 250;
float angle;
Servo servo;
// create a Servo object

void setup() {
  Serial.begin(9600);
  pinMode(lightPin, INPUT);
  pinMode(servoPin, OUTPUT);
  servo.attach(servoPin);
}

void loop() {
  lightVal = analogRead(lightPin);
  Serial.println(lightVal);
  delay(dt);

  angle = (-16.0 / 63.0) * lightVal + 16.0 * 780.0 / 63.0;
  servo.write(angle); 
}