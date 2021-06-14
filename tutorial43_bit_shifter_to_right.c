/*
 * Hexdecimal counter
 */
int latchPin = 11;
int clockPin = 9;
int dataPin = 12;
int dt = 250;

byte LEDs1 = 0b11110000; // 1111 1111 or we can directly do something like 0b00010001
byte LEDs2 = 0xbb;

void setup() {
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  // get the byte
  // keep shitinf it to the right,which means divided by 2
  while(LEDs1 >= 0b00000000) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin,LSBFIRST, LEDs1);
    digitalWrite(latchPin, HIGH);
    LEDs1 /= 2;
    delay(dt);
  }
}