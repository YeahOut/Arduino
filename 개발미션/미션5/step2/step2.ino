#include<SoftwareSerial.h>
#include<DFRobotDFPlayerMini.h>
#include<Adafruit_NeoPixel.h>

long randNumber;
SoftwareSerial mySerial(10,11);
DFRobotDFPlayerMini myDFPlayer;
Adafruit_NeoPixel strip(4, 7);


int sw = 2;

void setup() {
  strip.begin();
  mySerial.begin(9600);
  strip.setBrightness(127);
  myDFPlayer.begin(mySerial);
  strip.show();
  myDFPlayer.volume(20);
  pinMode(sw, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(sw) == LOW){
    long randNumber = random(21, 25);
    myDFPlayer.play(randNumber);
    strip.setPixelColor(1, 127, 0, 0);
    strip.setPixelColor(2, 127, 0, 0);
    strip.setPixelColor(3, 127, 0, 0);
    strip.setPixelColor(4, 127, 0, 0);
    strip.show();
    delay(8000);
  }
  else{
    myDFPlayer.stop();
    strip.clear();
    strip.show();
    delay(1000);
  }

}
