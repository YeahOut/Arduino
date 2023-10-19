#include <Arduino.h>
#include <Mecha_VoiceRecognition.h>
#include <SoftwareSerial.h>

const int moterPin=6;  

SoftwareSerial uart_voice(2, 3);
Mecha_VoiceRecognition voice(&uart_voice);

void setup() {
  pinMode(moterPin,OUTPUT);
    Serial.begin(9600); //PC-아두이노

      voice.setDebugOn(&Serial);
  voice.setGroup(VOICE_GROUP_1);
  voice.init();

  voice.setMode(VOICE_MODE_RECOGNITION);
}

void loop(){
    VOICE_InstructionTypeDef response = voice.getInstruction();
  switch(response) {
    case VOICE_INSTRUCTION_1:
      for(int i=0;i<1;i++){
    digitalWrite(moterPin,HIGH);
    delay(200);
    digitalWrite(moterPin,LOW);
    delay(200);
      }
      break;
    case VOICE_INSTRUCTION_2:
      for(int i=0;i<2;i++){
    digitalWrite(moterPin,HIGH);
    delay(200);
    digitalWrite(moterPin,LOW);
    delay(200);
      }
      break;
    case VOICE_INSTRUCTION_3:
      for(int i=0;i<3;i++){
    digitalWrite(moterPin,HIGH);
    delay(200);
    digitalWrite(moterPin,LOW);
    delay(200);
      }
      break;
    case VOICE_INSTRUCTION_4:
      for(int i=0;i<4;i++){
    digitalWrite(moterPin,HIGH);
    delay(200);
    digitalWrite(moterPin,LOW);
    delay(200);
      }
      break;
    case VOICE_INSTRUCTION_5:
      for(int i=0;i<5;i++){
    digitalWrite(moterPin,HIGH);
    delay(50);
    digitalWrite(moterPin,LOW);
    delay(50);
      }
      break;
    case VOICE_INSTRUCTION_ERROR:
      Serial.println("error");
      break;
    case VOICE_INSTRUCTION_NOTHING:
      // no data recieved
      break;
  }


}