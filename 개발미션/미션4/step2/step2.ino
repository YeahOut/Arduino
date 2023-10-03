#include<DHT.h>
#include<Adafruit_NeoPixel.h>
#include<LiquidCrystal_I2C.h>

DHT dht(4, DHT11);
Adafruit_NeoPixel strip(4, 7);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  dht.begin();
  strip.begin();
  strip.setBrightness(127);
}

void loop() {
  int hum = dht.readHumidity();
  int tem = dht.readTemperature();
  lcd.print("hum : ");
  lcd.print(hum);
  if(hum>60 || tem > 40){
    strip.setPixelColor(0, 0, 0, 127);
    strip.setPixelColor(1, 0, 0, 127);
    strip.setPixelColor(2, 0, 0, 127);
    strip.setPixelColor(3, 0, 0, 127);
    strip.show();
    delay(10);
  }
  else if(hum>55 && hum <=60){
    strip.setPixelColor(0, 0, 127, 0);
    strip.setPixelColor(1, 0, 127, 0);
    strip.setPixelColor(2, 0, 127, 0);
    strip.setPixelColor(3, 0, 127, 0);
    strip.show();
    delay(10);
  }
  else if(hum>50 && hum <=55){
    strip.setPixelColor(0, 127, 127, 127);
    strip.setPixelColor(1, 127, 127, 127);
    strip.setPixelColor(2, 127, 127, 127);
    strip.setPixelColor(3, 127, 127, 127);
    strip.show();
    delay(10);
  }
  else{
    strip.setPixelColor(0, 127, 0, 0);
    strip.setPixelColor(1, 127, 0, 0);
    strip.setPixelColor(2, 127, 0, 0);
    strip.setPixelColor(3, 127, 0, 0);
    strip.show();
    delay(10);
  }
  delay(500);
  strip.clear();

 
  
}
