int myNumber; // we will read the number from the serial monitor
String msg = "How Many Blinks Do You Want?:";
int redPin = 12;
int delayT = 500;

void setup() {
  Serial.begin(9600);
  pinMode(12, OUTPUT);
}

void loop() {
  Serial.println(msg);
  while (Serial.available() == 0){
    // while there is no data available
  }
  myNumber = Serial.parseInt(); // it will get the number
  Serial.println(myNumber);

  for(int i = 0; i < myNumber; i++){
    digitalWrite(12, HIGH);
    delay(delayT);
    digitalWrite(12, LOW);
    delay(2 * delayT);
  }
}