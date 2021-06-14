int potPin = A1;
int gPin = 6; 
int potVal; // the value read from analogRead of potentiometer, which is from 0 - 1023
float LEDVal; // the value of led

void setup() {
  pinMode(potPin, INPUT); // read from, so input
  pinMode(gPin, OUTPUT); // write to, so output
  Serial.begin(9600); // to print something
}

void loop() {
  // read the poval
  potVal = analogRead(potPin);
  // calculate LEDval
  LEDVal = potVal * (255.0 / 1023.0);
  // write to the led
  analogWrite(gPin, LEDVal);
  Serial.println(LEDVal);
}