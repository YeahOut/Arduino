int LED = 5;
int SW1 = 2;
int SW2 = 4;
int SL = 0;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(SW1)==LOW){
    if(SL<255){
      SL+=20;
    }
  }
  else if(digitalRead(SW2)==LOW){
    if(SL>0){
      SL-=20;
    }
  }
  analogWrite(LED, SL); 
  delay(300);
}