#include<Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial HC06(2, 3);
Servo servo;
int value = 0;

void setup() {
  Serial.begin(9600); //PC-아두이노
  pinMode(7, OUTPUT);
  HC06.begin(9600); //아두이노 - 블루투스 모듈
  pinMode(5, OUTPUT);
  servo.attach(8);
 }

void loop() {
   if(HC06.available()){
    long str = HC06.read();
    
    Serial.write(str);
    if(str <= 30)
    {
      value +=30;
    }
    else
    {
      value = 0;
    }
    servo.write(value);
    delay(100);
  }

}
