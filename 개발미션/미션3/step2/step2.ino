#include<Servo.h>
Servo servo;

int soil;
int cds = 0;
int led = 5;
int sw = 2;
int angle = 0;

void setup() {
  Serial.begin(9600);
  pinMode(sw, INPUT_PULLUP);
  servo.attach(8);
}

void loop() {
  soil = analogRead(A1);
  Serial.print("soil:");
  Serial.println(soil);
  delay(500);
 
 if(soil<500){
  tone(6, 131);
  delay(1000);
 }else{
  noTone(6);
 }
 if(digitalRead(sw)==LOW){
  angle+=90;
  servo.write(min(180,angle));
  delay(1000);
 }
 else if(digitalRead(sw)==HIGH){
  angle = 0;
  servo.write(angle);
 }
}
