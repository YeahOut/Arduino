#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

int echo = 12;
int trig = 13;
int led = 5;


void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH);
  long distance = (duration*340)/2/10000;
  int light = map(distance, 0, 40, 255, 0);
  
  if(distance>40){
    light = 0;
  }
  analogWrite(led, light);
  delay(500);

  lcd.print("Sonic Ruler");
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print("cm");

  lcd.setCursor(7, 1);
  lcd.print(light);
  delay(500);
  lcd.clear();
  Serial.println(light);
  delay(500);

}
