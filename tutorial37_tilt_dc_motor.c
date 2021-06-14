/*
 * Tutorial 37: Understanding how to control DC Motors in Projects
 */
 int speedPin = 5;
 int dir1 = 4;
 int dir2 = 3;
 int mSpeed = 230 ;// motor speed between 0 - 255, practically 

void setup() {
  Serial.begin(9600);
  pinMode(speedPin, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);

}

void loop() {
  // set the direction
  digitalWrite(dir1, HIGH);
  digitalWrite(dir2, LOW); 

  // KICK IT TO START
  analogWrite(speedPin, 255);
  delay(25);
  analogWrite(speedPin, mSpeed);
  delay(5000);
  
}