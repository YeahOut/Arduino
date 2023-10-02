void setup() {
  pinMode(2, OUTPUT);
  for(int i = 0; i<3;i++)
  {
    digitalWrite(2, HIGH);
    delay(1000);
    digitalWrite(2, LOW);
    delay(1000);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
