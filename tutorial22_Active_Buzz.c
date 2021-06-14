int myNumb;
int buzzPin = 8;
int dt1 = 1;
int dt2 = 2;
int myPin = A3;
float scale = (5.0 / 1023.0);
float v;


void setup() {
  Serial.begin(9600);
  pinMode(myPin, INPUT);
  pinMode(buzzPin, OUTPUT);
}

void loop() {

  // if the potentiometer becomes greater than 1000, make the buzz
  // read
 
  // check
  if (analogRead(myPin) > 1000){
    digitalWrite(buzzPin, HIGH);
    delay(delayT);
    digitalWrite(buzzPin, LOW);
  }
}