#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int LED_PINS[] = {4, 5, 6}; // LED 핀 배열
const int BUTTON_RED = 3; // 빨간색 버튼 핀
const int BUTTON_BLUE = 2; // 파란색 버튼 핀
const int REGISTOR = A0; // 가변 저항 핀
int ledState = 1; // 현재 LED 상태 (중앙 LED 점등)
int lastButtonState = HIGH; // 마지막 버튼 상태
int currentBrightness = 0; // 현재 밝기

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  
  for (int i = 0; i < 3; i++) {
    pinMode(LED_PINS[i], OUTPUT);
  }
  
  pinMode(BUTTON_RED, INPUT_PULLUP); // 내부 풀업 저항 사용
  pinMode(BUTTON_BLUE, INPUT_PULLUP); // 내부 풀업 저항 사용
}

void loop() {
  int val = analogRead(REGISTOR) / 4; // 0-1023 범위를 0-255 범위로 조정
  currentBrightness = val;
  analogWrite(LED_PINS[ledState], val); // 현재 LED의 밝기 조절

  // 빨간색 버튼이 눌렸는지 확인
  if (digitalRead(BUTTON_RED) == LOW && lastButtonState != LOW) {
    moveLED(-1); // 왼쪽으로 이동
    updateLCD("Red");
    lastButtonState = LOW; // 버튼 상태 업데이트
  }

  // 파란색 버튼이 눌렸는지 확인
  if (digitalRead(BUTTON_BLUE) == LOW && lastButtonState != LOW) {
    moveLED(1); // 오른쪽으로 이동
    updateLCD("Blue");
    lastButtonState = LOW; // 버튼 상태 업데이트
  }

  // 두 버튼이 동시에 눌렸는지 확인
  if (digitalRead(BUTTON_RED) == LOW && digitalRead(BUTTON_BLUE) == LOW) {
    turnOnAllLEDs(); // 모든 LED 켜기
    updateLCD("All");
    lastButtonState = LOW; // 버튼 상태 업데이트
  }

  // 버튼이 떼어졌는지 확인
  if (digitalRead(BUTTON_RED) == HIGH && digitalRead(BUTTON_BLUE) == HIGH) {
    lastButtonState = HIGH; // 버튼 상태 리셋
  }

  delay(100); // 디바운싱을 위한 간단한 딜레이
}

void moveLED(int direction) {
  // 현재 켜진 LED 끄기
  digitalWrite(LED_PINS[ledState], LOW);
  
  // LED 상태 업데이트
  ledState += direction;
  
  // 경계 검사
  if (ledState < 0) {
    ledState = 2; // 왼쪽 경계를 넘으면 가장 오른쪽 LED로
  } else if (ledState > 2) {
    ledState = 0; // 오른쪽 경계를 넘으면 가장 왼쪽 LED로
  }
  
  // 새로운 LED 켜기
  digitalWrite(LED_PINS[ledState], HIGH);
}

void turnOnAllLEDs() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED_PINS[i], HIGH);
  }
}

void updateLCD(String buttonName) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(buttonName + " switch: ");
  lcd.print(currentBrightness);
}
