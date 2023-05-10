#include <Arduino.h>
#include <FastLED.h>
#include "Location.h"

#define NUM_LEDS 256
#define DATA_PIN 3

CRGB leds[NUM_LEDS];

void light(Location loc, CRGB color = CRGB::Red) {
  uint16_t index = loc.get_index();
  leds[index] = color;
  FastLED.show();
  delay(1000);
}

uint16_t get_index(uint8_t x, uint8_t y) {
    if (y & 0x01) {
        uint8_t reversedX = (16 - 1) - x;
        return (y * 16) + reversedX;
    } else {
        return (y * 16) + x;
    }
  }

Location start = Location(7, 8);

void setup() { 
  randomSeed(analogRead(0));
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
  FastLED.setBrightness(5);
  FastLED.clear();
  Serial.begin(9600);
}


void loop() { 
  bool written[256];
  
  for (int i = 0; i < 20; i++) {
    
    int old_index = start.get_index();
    written[old_index] = 1;
    light(start);
    Serial.print("Found Location: ");
    Serial.println(start.get_index());

    while (written[start.get_index()]) {
      start.get_next_location();
      Serial.print("SKIPPING ");
      Serial.println(start.get_index());
    }
  }
  delay(5000);
  FastLED.clear();
  delay(100);
}







