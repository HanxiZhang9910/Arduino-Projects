/*
 * Tutorial 36: understanding how to use tilt switches in your projects
 */
int tiltPin = 2;
int tiltVal;
int redPin = 4;
int greenPin = 8;
 
void setup() {
  Serial.begin(9600);
  pinMode(tiltPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  digitalWrite(tiltPin, HIGH);
}

void loop() {
  tiltVal = digitalRead(tiltPin);
  Serial.println(tiltVal);

  if(tiltVal == 0){
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
  } else {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
  }
}