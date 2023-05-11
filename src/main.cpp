#include <Arduino.h>
#include <FastLED.h>
#include "Location.h"

#define NUM_LEDS 256
#define DATA_PIN 3
#define PRINT_ENABLED true

// TODO: migrate to Note.h
enum button {
  buttonRed,
  buttonOrange,
  buttonYellow,
  buttonGreen,
  buttonBlue,
  buttonPurple,
};
const int buttons[6] = {12, 11, 10, 6, 5, 4};

// TODO: probably end up as member of Keyboard class
// and referenced as pointer by Note objects
CRGB leds[NUM_LEDS];

//TODO: make member fields of Note class
bool writtenRed[256];
bool writtenOrange[256];
bool writtenYellow[256];
bool writtenGreen[256];
bool writtenBlue[256];
bool writtenPurple[256];


// TODO: init in Note constructor, change to 
// random start coord
Location* red = new Location(0,0);
Location* orange = new Location(12, 3);
Location* yellow = new Location(3, 7);
Location* green = new Location(0, 7);
Location* blue = new Location(7, 0);
Location* purple = new Location(3, 13);


// void myprint(String s, int x = 0) {

//   if (PRINT_ENABLED) {
//     Serial.print(s);
//     Serial.println(x);
//   }

// }


// TODO: migrate as method of Note class
void light(Location* loc, CRGB color, bool d = true) {

  uint16_t index = loc->get_index();
  leds[index] += color;
  FastLED.show();
  if (d) delay(50);

}



void setup() { 

  randomSeed(analogRead(0));
  // Serial.begin(9600);

  // TODO: migrate to Note.h constructor
  pinMode(12, INPUT); 
  pinMode(11, INPUT);
  pinMode(10, INPUT);
  pinMode(6, INPUT);
  pinMode(5, INPUT);
  pinMode(4, INPUT);

  
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
  FastLED.setBrightness(2);
  FastLED.clear();

}

void draw_line(Location* start, CRGB color, bool written[256]) {

  written[start->get_index()] = 1;
  light(start, color);
  while(written[start->get_index()]) {
    start->get_next_location();
  }
}

void loop() { 

  if(digitalRead(buttons[buttonRed]) == HIGH) {
    draw_line(red, CRGB::Red, writtenRed);
  }

  // if(digitalRead(buttons[buttonOrange]) == HIGH) {
  //   draw_line(orange, CRGB::Orange, writtenOrange);
  // }

  // if(digitalRead(buttons[buttonYellow]) == HIGH) {
  //   draw_line(yellow, CRGB::Yellow, writtenYellow);
  // }

  if(digitalRead(buttons[buttonGreen]) == HIGH) {
    draw_line(green, CRGB::Green, writtenGreen);
  }

  if(digitalRead(buttons[buttonBlue]) == HIGH) {
    draw_line(blue, CRGB::Blue, writtenBlue);
  }

  // if(digitalRead(buttons[buttonPurple]) == HIGH) {
  //   draw_line(purple, CRGB::Purple, writtenPurple);
  // }
  
}







