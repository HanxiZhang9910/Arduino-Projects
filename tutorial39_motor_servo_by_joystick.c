/*
 * Use a joystick to control the speed and the direction of the motor
 * and also to control the direction of a servo.
 */
# include<Servo.h>
 
int speedPin = 5;
int dir1 = 4;
int dir2 = 3;
float mSpeed;// motor speed between 0 - 255, practically 
int maxSpeed = 255;
int minSpeed = 100;

int xPin = A0;
int yPin = A1;
int sPin = 2; // switch pin

int yVal;
int xVal;

int servoPin = 9;
Servo myServo;

void setup() {
  Serial.begin(9600);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(sPin, INPUT);
  
  pinMode(speedPin, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);

  myServo.attach(servoPin);

  digitalWrite(sPin, HIGH);
}

void loop() {
  yVal = analogRead(yPin);
  xVal = analogRead(xPin);
  Serial.print(xVal);
  Serial.print(" "); 
  Serial.println(yVal);
  
  if (yVal > 520) {
    digitalWrite(dir1, HIGH);
    digitalWrite(dir2, LOW); 
    mSpeed = yVal * (155.0 / 509.0) - 56.52;
    if (mSpeed > maxSpeed){
      mSpeed = maxSpeed;
    }
    analogWrite(speedPin, mSpeed);
  } 

  if (yVal < 505) {
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, HIGH);
    mSpeed = yVal * (-155.0 / 512.0) + 255.0;
    if (mSpeed < maxSpeed){
      mSpeed = minSpeed;
    }
    analogWrite(speedPin, mSpeed);
  }

  if (yVal >= 505 && yVal <= 520){
    analogWrite(speedPin, 0);
  }

  int wValx = (180.0 / 1023.0) * xVal;
  myServo.write(wValx);
}