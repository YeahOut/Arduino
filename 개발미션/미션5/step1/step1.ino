#include<SoftwareSerial.h>
#include<DFRobotDFPlayerMini.h>

int led1 = 3;
int led2 = 4;
int led3 = 5;
int sw = 2;

long randNumber;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(sw, INPUT_PULLUP);
}

void loop() {
  randNumber = random(3, 6);
  if(digitalRead(sw) == LOW){
    digitalWrite(randNumber, HIGH);
    delay(3000);
    digitalWrite(randNumber, LOW);

  }
}
