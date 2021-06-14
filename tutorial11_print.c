int j = 1;
int x = 3;
int y = 7;
int z;
int waitTime = 750;
String myString = "j = ";
String plus = " + ";
String circle = "A circle with radius ";
String a = " has an area of ";
float pi = 3.14;
float r = 2;
float area;

void setup() {
  Serial.begin(115200); 
  // the only parameter is baud rate
  // which we have not talk about
}

void loop() {
//  Serial.println(myString + j);
//  j++;
//  z = x + y;
//
//  Serial.print(x);
//  Serial.print(plus);
//  Serial.print(y);
//  Serial.print(" = ");
//  Serial.println(z);
  Serial.print(circle);
  Serial.print(r);
  Serial.print(a);
  area = pi * r * r;
  Serial.print(area);
  Serial.println(".");
  delay(waitTime);
  r += 0.5;
}