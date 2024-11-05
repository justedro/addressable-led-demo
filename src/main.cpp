#include <Arduino.h>
#include <ESP8266WiFi.h>

#include <Adafruit_NeoPixel.h>

#define LED_PIN D3
#define NUM_LEDS 15


Adafruit_NeoPixel pixels(NUM_LEDS, LED_PIN, NEO_GRBW + NEO_KHZ800);

byte counter;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  Serial.println("Hello World");
  pinMode(D4, OUTPUT);

  pixels.setBrightness(50); // 0 - 255
  pixels.begin();
}

void loop() {
  pixels.clear();

  for(int i=0; i<NUM_LEDS; i++) {
    pixels.setPixelColor(i, pixels.ColorHSV(counter * 255, 255, 255));
    counter++;
    pixels.show();
    Serial.println("bonk");
    delay(500);
  }
}

