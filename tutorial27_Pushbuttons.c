int LEDPin = 8;
int buttonPin = 12;
int buttonRead;
int dt = 250;

void setup() {
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);
  pinMode(buttonPin, INPUT);
    
}

void loop() {
  buttonRead = digitalRead(buttonPin);
  Serial.println(buttonRead);
  delay(dt);

  if(buttonRead == 1){
    digitalWrite(LEDPin, HIGH);
    
  } else {
    digitalWrite(LEDPin, LOW);
  }

}