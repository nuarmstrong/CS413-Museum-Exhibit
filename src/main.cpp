#include <Arduino.h>
#include <FastLED.h>
#include <Location.h>

#define NUM_LEDS 256
#define DATA_PIN 3

CRGB leds[NUM_LEDS];

void light(Location loc, CRGB color = CRGB::Red);

Location start = Location(7, 8);

void setup() { 
  randomSeed(analogRead(0));
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
  FastLED.setBrightness(1);
  FastLED.clear();
}

void loop() { 
  bool written[256];
  
  for (int i = 0; i < 20; i++) {
    
    int old_index = start.get_index();
    written[old_index] = 1;
    light(start);

    while (true) { // keep iterating until we find an unwritten index
      start.get_next_location();
      int new_index = start.get_index();
      if (!written[new_index]) {
        break; // found an unwritten index, break out of the loop
      }
    }
  }
  delay(5000);
  FastLED.clear();
  delay(100);
}

void light(Location loc, CRGB color = CRGB::Red) {
  uint16_t index = loc.get_index();
  leds[index] = color;
  FastLED.show();
  delay(1000);
}





