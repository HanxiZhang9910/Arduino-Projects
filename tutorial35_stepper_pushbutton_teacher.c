/*
 * The step motor will keep making revolution until the button is pressed, then the  
 * step motor will turn to the other direction and keeping making revolution
 */
#include<Stepper.h>
int stepsPerRevolution = 2048; 
int motSpeed = 15; // 10 rpm, revolution per minute?
int dt = 500;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11); // send the parameter, which means the steps per revolution

int buttonPin = 2;
int motDir = 1; // keep track of the direction of the stepper motor
int buttonValNew;
int buttonValOld = 1; // where the button was last time

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(motSpeed);
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH); // it puts 5 volts there
}

void loop() {
  buttonValNew = digitalRead(buttonPin);
  if (buttonValOld == 1 && buttonValNew == 0){
    motDir = motDir * -1; // change the motor direction if the button is pressed
  }
  myStepper.step(motDir * 1);
  buttonValOld = buttonValNew;
}