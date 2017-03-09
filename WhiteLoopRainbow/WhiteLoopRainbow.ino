#include <Adafruit_NeoPixel.h>
#define PIN 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(150, PIN, NEO_GRB + NEO_KHZ800);
const int rgbChangeSpeed = 5;

int red = 255;
int green = 0;
int blue = 0;

const int colorMax = 100;

int currentPos = 0;
const int whiteLength = 3;
const int whiteSpeed = 1;

int tempIndex;

int lastPos = 150;
uint32_t lastColor;

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.show();
}

void loop() {
  if (currentPos < lastPos) {
    lastColor = strip.Color(red,green,blue);
    nextRGB();
  }
  lastPos = currentPos;
  tempIndex = currentPos;
  while (tempIndex != (currentPos + whiteLength) % 150) {
    strip.setPixelColor(tempIndex,100,100,100);
    tempIndex = (tempIndex + 1) % 150;
  }

  for (int i = 0; i < currentPos; i++) {
    strip.setPixelColor(i,red,green,blue);
  }

  for (int i = currentPos + whiteLength + 1; i < 150; i++) {
    strip.setPixelColor(i,lastColor);
  }
  strip.show();
  currentPos += whiteSpeed;
  delay(10);
}

void nextRGB() {
  if (red == colorMax && green < colorMax && blue == 0) {
    green += rgbChangeSpeed;
  } else if (green == colorMax && red > 0 && blue == 0) {
    red -= rgbChangeSpeed;
  } else if (green == colorMax && blue < colorMax && red == 0) {
    blue += rgbChangeSpeed;
  } else if (blue == colorMax && green > 0 && red == 0) {
    green -= rgbChangeSpeed;
  } else if (blue == colorMax && red < colorMax && green == 0) {
    red += rgbChangeSpeed;
  } else if (red == colorMax && blue > 0 && green == 0) {
    blue -= rgbChangeSpeed;
  }
}

