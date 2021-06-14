int lightPen = A0;
int lightVal;
int dv = 250; // in miliseconds
int greenPin = 5;
int redPin = 3;

void setup() {
  pinMode(lightPen, INPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  lightVal = analogRead(lightPen); // get the value of the photoresistor
  Serial.println(lightVal); 
  delay(dv);

  if (lightVal >= 500){
    digitalWrite(greenPin, HIGH);
    delay(dv);
    digitalWrite(greenPin, LOW);
    delay(dv);

  } else {
    digitalWrite(redPin, HIGH);
    delay(dv);
    digitalWrite(redPin, LOW);
    delay(dv);
  }

}