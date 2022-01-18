#include <SR04.h>
const int trigpin =10;
const int echopin =11;
const int ledpin =12;
const int ldrpin =A0;

long duration;
int distance;

void setup() {
  Serial.begin (9600);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(ledpin,OUTPUT);
  pinMode(ldrpin,INPUT);
 
}

void loop() {
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);

  duration = pulseIn(echopin, HIGH);

  distance = (duration/2) / 29.1;
  
  if (distance <=15)
  
  { digitalWrite(ledpin,HIGH);
    Serial.print(distance);
    Serial.println(" cm");
    delay(30000);
  }
  
  else {
  
  digitalWrite(ledpin,LOW);
  Serial.print(distance);
  Serial.println(" cm");
  
  }
  
 int ldrStatus = analogRead(ldrpin);

 if (ldrStatus <= 10)
  {
    digitalWrite(ledpin, HIGH);
    Serial.print("Its Dark, Turn on the lights:");
    Serial.println(ldrStatus);
    delay(30000);
  }
  else
  {
    digitalWrite(ledpin, LOW);
    Serial.print("Its Bright, Turn off the lights:");
    Serial.println(ldrStatus);
  }
  
delay(500);
}