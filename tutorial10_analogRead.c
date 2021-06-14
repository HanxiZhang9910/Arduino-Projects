int readPin = A3;
int readVal;
float V2 = 0.0;
int delayTime = 500;

void setup() {
  // put your setup code here, to run once: 
  // pinMode(pin9, OUTPUT);
  pinMode(readPin, INPUT);
  Serial.begin(9600); // we are setting up the serial monitor where 
  // we can print to it
  
}

void loop() {
  // put your main code here, to run repeatedly:
  // analogRead will return a value
  readVal = analogRead(readPin); // parameter is the pin to read from
  V2 = readVal * (5.0/1023.0); // it should have decimal points to become floats
  // we will read V2, and print it
  Serial.println(V2);
  // because it is so fast, we can add a delay to it
  delay(delayTime);
}