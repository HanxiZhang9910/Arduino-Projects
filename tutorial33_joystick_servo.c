/*
 * Learned how to use joystick to control two servos.
 */


# include<Servo.h>
Servo s1;
Servo s2;

int xPin = A0;
int yPin = A1;
int sPin = 2; // switch pin
int xServoPin = 9;
int yServoPin = 10;
int buzzPin = 7;
int wValX;
int wValY; // write value for 
int xVal;
int yVal;
int sVal; // switch value
int dt = 200;

void setup() {
  Serial.begin(9600);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(sPin, INPUT);
  
  pinMode(xServoPin, OUTPUT);
  pinMode(yServoPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  digitalWrite(sPin, HIGH);

  s1.attach(xServoPin);
  s2.attach(yServoPin);
}

void loop() {
  xVal = analogRead(xPin); // calculate the angle based on the ratio
  wValX = (180.0 / 1023.0) * xVal;
  
  yVal = analogRead(yPin);
  wValY = (180.0 / 1023.0) * yVal; // angle send to y servo

  sVal = digitalRead(sPin);

  s1.write(wValX);
  s2.write(wValY);

  if(sVal == 0){
    digitalWrite(buzzPin, HIGH);
  } else {
    digitalWrite(buzzPin, LOW);
  }

  delay(dt);

  Serial.print(xVal);
  Serial.print(" ");
  Serial.print(yVal);
  Serial.print(" ");
  Serial.print(sVal);
  Serial.println(" ");
}