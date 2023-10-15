#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Mecha_VoiceRecognition.h>
#include <LiquidCrystal_I2C.h>

#define PIN_LED_GREEN 4
#define PIN_LED_YELLOW 5
#define PIN_LED_RED 6

SoftwareSerial HC06(7, 8); //RXD, TXD 반대로
SoftwareSerial uart_voice(2, 3);
Mecha_VoiceRecognition voice(&uart_voice);

int echo = 11;
int trig = 10;

void setup() {
  pinMode(PIN_LED_GREEN, OUTPUT);
  pinMode(PIN_LED_YELLOW, OUTPUT);
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  Serial.begin(9600);
  HC06.begin(9600);
  
  voice.setDebugOn(&Serial);
  voice.setGroup(VOICE_GROUP_1);
  voice.init();

  voice.setMode(VOICE_MODE_RECOGNITION);
}

void loop() {
  VOICE_InstructionTypeDef response = voice.getInstruction();
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  long duration = pulseIn(echo, HIGH);
  long distance = (duration * 340)/2/10000;
  int map_distance = map(distance, 0, 50, 0, 10);

  if(map_distance < 4){
    HC06.write(7);
    Serial.print("거리가 가까움");
  }

  switch(response) {
    case VOICE_INSTRUCTION_1:
      Serial.println("Red");
      digitalWrite(PIN_LED_GREEN, LOW);
      digitalWrite(PIN_LED_YELLOW, LOW);
      digitalWrite(PIN_LED_RED, HIGH);
      HC06.write(1);
      break;
    case VOICE_INSTRUCTION_2:
      Serial.println("Yellow");
      digitalWrite(PIN_LED_GREEN, LOW);
      digitalWrite(PIN_LED_YELLOW, HIGH);
      digitalWrite(PIN_LED_RED, LOW);
      HC06.write(2);
      break;
    case VOICE_INSTRUCTION_3:
      Serial.println("Green");
      digitalWrite(PIN_LED_GREEN, HIGH);
      digitalWrite(PIN_LED_YELLOW, LOW);
      digitalWrite(PIN_LED_RED, LOW);
      HC06.write(3);
      break;
    case VOICE_INSTRUCTION_4:
      Serial.println("White");
      digitalWrite(PIN_LED_GREEN, HIGH);
      digitalWrite(PIN_LED_YELLOW, HIGH);
      digitalWrite(PIN_LED_RED, HIGH);
      HC06.write(4);
      break;
    case VOICE_INSTRUCTION_5:
      Serial.println("Black");
      digitalWrite(PIN_LED_GREEN, LOW);
      digitalWrite(PIN_LED_YELLOW, LOW);
      digitalWrite(PIN_LED_RED, LOW);
      HC06.print(5);
      break;
    case VOICE_INSTRUCTION_ERROR:
      Serial.println("error");
      HC06.write(6);
      break;
    case VOICE_INSTRUCTION_NOTHING:
      // no data recieved
      break; 
  }
  
  delay(500);
}