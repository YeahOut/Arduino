int LED = 5;
int SW1 = 2;
int SW2 = 4;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);

}

void loop() {
  if(digitalRead(SW1)==LOW){
    digitalWrite(LED, HIGH);
  }
  else if(digitalRead(SW2)==LOW){
    digitalWrite(LED, LOW);
  }
  
}
