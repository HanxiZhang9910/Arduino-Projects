int myVoltPin = A2;
int readVal;
float V2; // the voltage across R2
int waitTime = 500;

void setup() {
  Serial.begin(9600);
}

void loop() {
  readVal = analogRead(myVoltPin);
  V2 = readVal * (5.0 / 1023.0);
  Serial.println(V2); // it should keep printing the voltage we got
  // from the center leg of the potentiometer.
  delay(waitTime);
}   