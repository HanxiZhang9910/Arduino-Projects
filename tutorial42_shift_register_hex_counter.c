/*
 * Hexdecimal counter
 */
int latchPin = 11;
int clockPin = 9;
int dataPin = 12;
int dt = 250;

byte LEDs1 = 0b00010011; // 1111 1111 or we can directly do something like 0b00010001
byte LEDs2 = 0xbb;

void setup() {
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  digitalWrite(latchPin, LOW); // tell the register that data is incoming
  shiftOut(dataPin, clockPin, LSBFIRST, LEDs1) ; // on pin 12, send out the data, 
  // input which pin to use as the clock pin to do sychronize
  // then input the parameter indicate the order of the hexdecimal, which is least significant first
  // finally input the data packet which is LEDs
  digitalWrite(latchPin, HIGH);
  delay(dt);

  for (byte i = 0; i < 256; i++){
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, i);
    digitalWrite(latchPin, HIGH);
    delay(dt);
  }
}