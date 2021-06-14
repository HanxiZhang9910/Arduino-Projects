int myPin = A2;
int readVal;
float scale = (5.0 / 1023.0);
float v2;
int delayTime = 250;
int redPin = 9;

void setup() {
  Serial.begin(9600);
  pinMode(myPin, INPUT);
  pinMode(redPin, OUTPUT);
  
}

void loop() {
  readVal = analogRead(myPin);
  v2 = scale * readVal;
  if(v2 >= 4.0 && v2<=5.0){
    digitalWrite(redPin, HIGH);
    delay(delayTime);
    digitalWrite(redPin, LOW);
  } else if (v2 >= 3.5 || v2 <= 1.0){
    digitalWrite(redPin, HIGH);
    delay(delayTime * 0.5);
    digitalWrite(redPin, LOW);
  }
  Serial.print("Potentiometer Voltage: ");
  Serial.println(v2);
  delay(delayTime);
}