/*
 * Stepmotor, we can have very precise control of it
 * At low rpm, it has very big torque, Servos do not have much 
 * precise control and small torque.
 * 
 * Disadvantage: it draws a lot of current
 */

#include<Stepper.h>
int stepsPerRevolution = 2048; 
int motSpeed = 15; // 10 rpm, revolution per minute?
int dt = 500;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11); // send the parameter, which means the steps per revolution

int buttonPin = 2;
int buttonVal;
int dt_button = 100;

int buttonNew;
int buttonOld = 1;
int revoStatus = 0; // the status of revolution, which is the direction of the revolution
int counter = 0;

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(motSpeed);
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
}

void loop() {
  buttonNew = digitalRead(buttonPin);

  if(buttonOld == 0 && buttonNew == 1){
    if(revoStatus == 0){
      myStepper.step(stepsPerRevolution); // how many steps
      revoStatus = 1;
    } else {
      stepsPerRevolution = -stepsPerRevolution;
      myStepper.step(-stepsPerRevolution); // how many steps
      revoStatus = 0;
    }
  }

  buttonOld = buttonNew;
  Serial.print("Your Button is: ");
  Serial.println(buttonVal);
  delay(dt_button);
}