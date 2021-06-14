int LEDPin = 8;
int buttonPin = 12;
int buttonRead;
int dt = 250;
int pushCount = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);
  pinMode(buttonPin, INPUT);
    
}


void loop() {
  buttonRead = digitalRead(buttonPin);
//  Serial.println(buttonRead);
  Serial.println("push: ");
  Serial.println(pushCount);

  if(buttonRead == 0 && digitalRead(buttonPin) == 1){            
    pushCount+=1;

  } 

  if(pushCount % 2 == 0){
    digitalWrite(LEDPin, HIGH);
  } else {
    digitalWrite(LEDPin, LOW);
  }
}