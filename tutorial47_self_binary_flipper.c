 
int latchPin = 11;
int clockPin = 9;
int dataPin = 12;
int dt = 250;
int curr;

byte LEDs1 = 0b10010001; // 1111 1111 or we can directly do something like 0b00010001
byte LEDs2 = 0xbb;

void setup() {
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

/**
 * get the number, keep shifting it to the right (dividing by two)
 */
int mostSignificant(byte num){
  num = num >> (8 - 1); // shift the number to the right
  return num;
}

int leastSignificant(byte num){
  return num % 2;
}

void loop() {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin,LSBFIRST, LEDs1);
    Serial.println(LEDs1, BIN);
    digitalWrite(latchPin, HIGH);
    LEDs1 = ~ LEDs1;
    // 
    delay(dt);
}