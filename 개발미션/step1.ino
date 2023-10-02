
char a = 'A';
int b = 3;
float c = 61.324;

void setup(){
  Serial.begin(9600);
}

void loop(){
  Serial.print("혈액형 : ");
  Serial.print(a);
  Serial.println("형");
  Serial.print("나이 : ");
  Serial.print(b);
  Serial.println("살");
  Serial.print("키 : ");
  Serial.print(c);
  Serial.println("cm");
  delay(5000);
}

