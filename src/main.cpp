#include <Arduino.h>
#include <FastLED.h>
#include "Location.h"
#include "Note.h"

#define NUM_LEDS 256
#define DATA_PIN 3
#define PRINT_ENABLED false

CRGB leds[NUM_LEDS];

Note A = Note(buttonRed, CRGB::Red, &leds);
Note B = Note(buttonOrange, CRGB::Orange, &leds);
Note C = Note(buttonYellow, CRGB::Yellow, &leds);
Note D = Note(buttonGreen, CRGB::Green, &leds);
Note E = Note(buttonBlue, CRGB::Blue, &leds);
Note F = Note(buttonPurple, CRGB::Purple, &leds);

// void myprint(String s, int x = 0) {

//   if (PRINT_ENABLED) {
//     Serial.print(s);
//     Serial.println(x);
//   }

// }

void setup() { 

  randomSeed(analogRead(0));
  // Serial.begin(9600);
  
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
  FastLED.setBrightness(2);
  FastLED.clear();

}


void loop() { 

  if(A.pushed()) A.draw_line();
  if(B.pushed()) B.draw_line();
  if(C.pushed()) C.draw_line();
  if(D.pushed()) D.draw_line();
  if(E.pushed()) E.draw_line();
  if(F.pushed()) F.draw_line();

}







