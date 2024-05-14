#include <Arduino.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

Servo myservo;
LiquidCrystal_I2C lcd(0x27, 16, 2);

int trigPin = D1;
int echoPin = D2;
int ledmPin = D3;
int ledhPin = D4;
int SDAPin = D6;
int SCLPin = D7;

long duration;
int distance;

void setup()
{
  // put your setup code here, to run once:
  myservo.attach(D5);
  pinMode(ledmPin, OUTPUT);
  pinMode(ledhPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Wire.begin(SDAPin, SCLPin);
  Serial.begin(9600);
}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = 0.034 * duration / 2;
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Jarak: ");
  lcd.print(distance);
  lcd.print("cm");
  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");
  if (distance <= 10)
  {
    digitalWrite(ledmPin, LOW);
    digitalWrite(ledhPin, HIGH);
    myservo.write(90);
  }
  else
  {
    digitalWrite(ledhPin, LOW);
    digitalWrite(ledmPin, HIGH);
    myservo.write(0);
  }
  delay(1000);
}