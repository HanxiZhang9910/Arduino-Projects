int myNumb;
int buzzPin = 8;
int dt1 = 1;
int dt2 = 2;
int myPin = A3;
float scale = (5.0 / 1023.0);
float v;


void setup() {

  pinMode(buzzPin, OUTPUT);
}

void loop() {
  for(int i = 0; i <= 100; i++){
    digitalWrite(buzzPin, HIGH);
    delay(dt1);
    digitalWrite(buzzPin, LOW);
    delay(dt1);
    
  }

  for(int i = 1; i <= 100; i++){
    digitalWrite(buzzPin, HIGH);
    delay(dt2);
    digitalWrite(buzzPin, LOW);
    delay(dt2);
  }
}