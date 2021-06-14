// dimmable LED is from 0 - 255
// every time push the button or press the button for a time, 
// it will increase the value of the LED, making it brighter
int upButton = 11;
int downButton = 10;
int ledButton = 6;
float ledVal = 1.0;
int dt = 250;

void setup() {
  Serial.begin(9600);
  pinMode(upButton, INPUT);
  pinMode(downButton, INPUT);
  pinMode(ledButton, OUTPUT);
}

void loop() {
  Serial.println(digitalRead(upButton));
  Serial.println(digitalRead(downButton));

  // if up button is pressed, make it brighter
  // check digital read, and keep adding that value
  if (digitalRead(upButton) == 0){
    // press the up button
    if (ledVal <= 254){
      ledVal += 1;
    }
    
    analogWrite(ledButton, ledVal);

    // warning
    if (ledVal >= 255){
      for (int i = 0; i < 10; i++){
        digitalWrite(ledButton, HIGH);
        delay(dt);
        digitalWrite(ledButton, LOW);
        delay(dt);   
      } 
      digitalWrite(ledButton, HIGH);
    }
  }

    if (digitalRead(downButton) == 0){
    // press the up button
      if (ledVal > 0){
        ledVal -= 1;
      }
    analogWrite(ledButton, ledVal);

    // warning
    if (ledVal <= 0){
      for (int i = 0; i < 10; i++){
        digitalWrite(ledButton, HIGH);
        delay(dt);
        digitalWrite(ledButton, LOW);
        delay(dt);   
      } 
    }
  }
  // if down button is pressed, make it dimmer
//  digitalWrite(ledButton, HIGH);
//  delay(dt);
//  digitalWrite(ledButton, LOW);
//  delay(dt);
}