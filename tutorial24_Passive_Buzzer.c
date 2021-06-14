int buzzPin = 8;
int potPin = A1;
int potVal;
int toneVal;

void setup() {
  pinMode(buzzPin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  potVal = analogRead(potPin);
  toneVal = (9940.0 / 1023.0) * potVal + 60.0;
  
  digitalWrite(buzzPin, HIGH);
  delayMicroseconds(toneVal);
  digitalWrite(buzzPin, LOW);
  delayMicroseconds(toneVal);
  
}