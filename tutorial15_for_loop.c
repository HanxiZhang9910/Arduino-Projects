int yellowPin = 6;
int redPin = 9;
int delayT = 500;

void setup() {
  pinMode(yellowPin, OUTPUT); // read from, so input
  pinMode(redPin, OUTPUT); // write to, so output
  Serial.begin(9600); // to print something
}

void loop() {
  for (int i = 0; i < 3; i++){
    digitalWrite(yellowPin, HIGH);
    delay(delayT);
    digitalWrite(yellowPin, LOW);
    delay(delayT);
  }

  for (int i = 0; i < 5; i++){
    digitalWrite(redPin, HIGH);
    delay(delayT);
    digitalWrite(redPin, LOW);
    delay(delayT);
  }
}