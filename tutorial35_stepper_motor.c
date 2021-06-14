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


void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(motSpeed);
}

void loop() {
  myStepper.step(stepsPerRevolution/3); // how many steps
  delay(dt);
  myStepper.step(-stepsPerRevolution/3); // how many steps
  delay(dt);
}