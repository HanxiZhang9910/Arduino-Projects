String colorName;
String msg = "What color do you want?";
int redPin = 4;
int greenPin = 7;
int bluePin = 12;
int delayT = 500;

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // ask
  Serial.println(msg);
  // wait
  while(Serial.available() == 0){
  }
  // get
  colorName = Serial.readString();

  if (colorName == "red"){
    digitalWrite(redPin, HIGH);
    delay(delayT);
    digitalWrite(redPin, LOW);
    
  } else if (colorName == "green"){
    digitalWrite(greenPin, HIGH);
    delay(delayT);
    digitalWrite(greenPin, LOW);

  } else if (colorName == "blue"){
    digitalWrite(bluePin, HIGH);
    delay(delayT);
    digitalWrite(bluePin, LOW);

  }
}