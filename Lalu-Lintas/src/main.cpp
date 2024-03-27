#include <Arduino.h>

// put function declarations here:
int redLED = D0;
int yellowLED = D1;
int greenLED = D2;

void setup()
{
  // put your setup code here, to run once:
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(redLED, HIGH);
  delay(30000);
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, HIGH);
  delay(5000);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, HIGH);
  delay(30000);
  digitalWrite(greenLED, LOW);
}

// put function definitions here: