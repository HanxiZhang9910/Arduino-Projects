byte mybyte = 0x0; // B0

int dt = 100; 
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print(mybyte, HEX); // print in hex
  Serial.print(" ");
  Serial.print(mybyte, DEC);
  Serial.print(" ");
  Serial.print(mybyte1, BIN); // print in BINARY
  Serial.print(" ");
  mybyte++;
  delay(dt);
}