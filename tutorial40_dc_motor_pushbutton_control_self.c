/*
 * Use two pushbuttons to control the speed and direction of the motor
 * The motor starts at off
 * If keep pushing the right button, the motor starts make revolution at a direction
 * If keep pushing the left one, the motor slows down
 * If keep pushing the left button more, it will stop, then start to turn the other 
 * If pushing the right, it will slows down(towards zero)
 */
// motor pins
int speedPin = 5;
int dir1 = 4;
int dir2 = 3;
int mSpeed = 100;

int buttonPin1 = 12;
int buttonPin2 = 13;
int buttonVal1;
int buttonVal2;
int dt = 100;
int counter2 = 0;
int counter1 = 0;

void setup() {
  Serial.begin(9600);
  // motor pins
  pinMode(speedPin, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);

  // pushbutton setup
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  digitalWrite(buttonPin1, HIGH);
  digitalWrite(buttonPin2, HIGH);
}

void loop() {
  buttonVal1 = digitalRead(buttonPin1);
  Serial.print("Your Button 1 is: ");
  Serial.println(buttonVal1);
  buttonVal2 = digitalRead(buttonPin2);
  Serial.print("Your Button 2 is: ");
  Serial.println(buttonVal2);
  Serial.print("counter1: ");
  Serial.println(counter1);
  Serial.print("counter2: ");
  Serial.println(counter2);
  delay(dt);

  if(!buttonVal1){
    counter1++;
  }
  if(!buttonVal2){
    counter2++;
  }

  // the motor starts at off position
  if (abs(counter1 - counter2) < 5){
    analogWrite(speedPin, 0);
  } else {
    if (counter2 > counter1){
      //positive direction
      digitalWrite(dir1, HIGH);
      digitalWrite(dir2, LOW);
      if (buttonVal2 == 0){
        mSpeed+=10;
      } 
      if (buttonVal1 == 0){
        mSpeed-=0;
      }
      if (mSpeed > 255){
        mSpeed = 255;
      } else if (mSpeed < 0){
        mSpeed = 0;
      }
      analogWrite(speedPin, mSpeed);
    } else { // when counter 2 < counter1
        digitalWrite(dir1, LOW);
        digitalWrite(dir2, HIGH);
        if (buttonVal2 == 0){
          mSpeed-=10;
        
        } 
        if (buttonVal1 == 0){
          mSpeed+=0;
       
        }
        if (mSpeed > 255){
          mSpeed = 255;
        } else if (mSpeed < 0){
          mSpeed = 0;
        }
        analogWrite(speedPin, mSpeed);
    }
  }
}