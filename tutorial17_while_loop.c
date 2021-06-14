int potVal; // value read from potentiometer
int potPin = A0;
int redPin = 7;
int delayTime = 500;

void setup() {
  Serial.begin(9600);
  pinMode(potPin, INPUT);
  pinMode(redPin, OUTPUT);
}

void loop() {
  potVal = analogRead(potPin);
  Serial.println(potVal);
  delay(500);

  while(potVal > 1000){
    digitalWrite(redPin, HIGH); // if it is greater, put a warnin
    potVal = analogRead(potPin); // if we don't read, potVal will not change
    delay(delayTime);
  }
  digitalWrite(redPin, LOW); // if it is outside the loop, set the light off
}