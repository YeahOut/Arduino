#include <Servo.h>
#include <Wire.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define LED_COUNT 3
#define DHTPIN A1
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const int tactSwitchPin = 2;
LiquidCrystal_I2C lcd(0x27, 16, 2);

int ledIndex = 0;

Servo servo;

void setup() {
   lcd.begin(16, 2);
  lcd.print("LED Switch");
  pinMode(tactSwitchPin, INPUT_PULLUP);
  pinMode(4, OUTPUT); 
pinMode(5, OUTPUT); 
pinMode(6, OUTPUT); 
  servo.attach(9);
}

void loop() {
  int val = analogRead(A2);
  int angle = map(val, 0, 1023, 0, 179);

  servo.write(angle);
  delay(50);
    if (digitalRead(tactSwitchPin) == LOW) {
    digitalWrite(4, HIGH);
  }

}

