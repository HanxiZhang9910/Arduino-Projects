/*
 * The simplest way to use a pushbutton switch without 
 * using a resistor
 * 
 */

int buttonPin = 2;
int buttonVal;
int dt = 100;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
}

void loop() {
  buttonVal = digitalRead(buttonPin);
  Serial.print("Your Button is: ");
  Serial.println(buttonVal);
  delay(dt);
}