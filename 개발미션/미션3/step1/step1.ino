int cds = 0;
int LED = 5;
int SL = 255;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  cds = analogRead(A0);
  Serial.print("cds:");
  Serial.println(cds);
  delay(500);
  analogWrite(LED, SL); 

  if (cds > 750) {
    for (int i = 0; i < 2 && cds > 750; i++) {
      // 도
      cds = analogRead(A0);
      if (cds <= 750) {
        noTone(6);
        return;
      }
      tone(6, 33); 
      delay(1000);
      SL = max(0, SL - 40);
      analogWrite(LED, SL); 

      // 미
      cds = analogRead(A0);
      if (cds <= 750) {
        noTone(6);
        return;
      }
      tone(6, 41); 
      delay(1000);
      SL = max(0, SL - 40);
      analogWrite(LED, SL); 

      // 솔
      cds = analogRead(A0);
      if (cds <= 750) {
        noTone(6);
        return;
      }
      tone(6, 49); 
      delay(1000);
      SL = max(0, SL - 40);
      analogWrite(LED, SL); 
    }

    for (int i = 0; i < 3 && cds > 750; i++) {
      // 라
      cds = analogRead(A0);
      if (cds <= 750) {
        noTone(6);
        return;
      }
      tone(6, 55); 
      delay(1000);
      SL = max(0, SL - 40);
      analogWrite(LED, SL); 
    }

    // 솔
    cds = analogRead(A0);
    if (cds <= 750) {
      noTone(6);
      return;
    }
    tone(6, 49); 
    delay(1000);
    SL = max(0, SL - 40);
    analogWrite(LED, SL); 

    for (int i = 0; i < 3 && cds > 750; i++) {
      // 파
      cds = analogRead(A0);
      if (cds <= 750) {
        noTone(6);
        return;
      }
      tone(6, 44); 
      delay(1000);
      SL = max(0, SL - 40);
      analogWrite(LED, SL); 
    }

    for (int i = 0; i < 3 && cds > 750; i++) {
      // 미
      cds = analogRead(A0);
      if (cds <= 750) {
        noTone(6);
        return;
      }
      tone(6, 41); 
      delay(1000);
      SL = max(0, SL - 40);
      analogWrite(LED, SL); 
    }

    for (int i = 0; i < 3 && cds > 750; i++) {
      // 레
      cds = analogRead(A0);
      if (cds <= 750) {
        noTone(6);
        return;
      }
      tone(6, 37); 
      delay(1000);
      SL = max(0, SL - 40);
      analogWrite(LED, SL); 
    }

    // 도
    cds = analogRead(A0);
    if (cds <= 750) {
      noTone(6);
      return;
    }
    tone(6, 33); 
    delay(1000);
    SL = max(0, SL - 40);
    analogWrite(LED, SL); 

    noTone(6); 
  }
}


















