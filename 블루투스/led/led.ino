//슬레이브 코드
#include <SoftwareSerial.h>
SoftwareSerial HC06(2, 3);
void setup() 
{
  Serial.begin(9600); //PC-아두이노
  pinMode(7, OUTPUT);
  HC06.begin(9600); //아두이노 - 블루투스 모듈
  pinMode(5, OUTPUT);
}

void loop(){
    if(HC06.available()){
    char str = HC06.read();
    Serial.write(str);
    if(str == '1')
    {
      digitalWrite(5, HIGH);
    }
    else
    {
      digitalWrite(5, LOW);
    }
  }
  //if(Serial.available())
  //HC06.write(Serial.read());
}