#include <Arduino.h>
#include <FastLED.h>
#include "Location.h"

#define NUM_LEDS 256
#define DATA_PIN 3
#define PRINT_ENABLED false

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
Location red = Location(3, 3);
Location orange = Location(12, 3);
Location yellow = Location(3, 7);
Location green = Location(12, 13);
Location blue = Location(7, 13);
Location purple = Location(3, 13);


void myprint(String s, int x = 0) {

  if (PRINT_ENABLED) {
    Serial.print(s);
    Serial.println(x);
  }

}

// TODO: migrate as method of Note class
void light(Location loc, CRGB color, bool d = true) {

  uint16_t index = loc.get_index();
  leds[index] += color;
  FastLED.show();
  if (d) delay(50);

}

// Redundant from location.h, needed for debugging
uint16_t get_index(uint8_t x, uint8_t y) {

    if (x & 0x01) {
        uint8_t reversedY = (16 - 1) - y;
        return (x * 16) + reversedY;
    } else {
        return (x * 16) + y;
    }

  }

void setup() { 

  randomSeed(analogRead(0));
  Serial.begin(9600);

  // TODO: migrate to Note.h constructor
  pinMode(12, INPUT); 
  pinMode(11, INPUT);
  pinMode(10, INPUT);
  pinMode(6, INPUT);
  pinMode(5, INPUT);
  pinMode(4, INPUT);

  
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
  FastLED.setBrightness(7);
  FastLED.clear();
  for (int i = 0; i < 256; i++) {
    leds[i] = CRGB::Black;
  }

}

void draw_line(Location start, CRGB color) {
  // This is the same logic running in loop(), 
  // but non-functional when called directly?

  int old_index = start.get_index();
  writtenRed[old_index] = 1;
  myprint("Lighting location: ", old_index);
  // delay(500);
  light(start, color);

  while(writtenRed[start.get_index()]) {
    start.get_next_location();
    int new_index = start.get_index();
    myprint("trying new index: ", new_index);
    // delay(200);
    if (writtenRed[new_index]) { 
      myprint("Summing to ", old_index);
      // leds[new_index] += leds[old_index];
    }
  }

}

void loop() { 

  // This is the problem: only two of these can run at 
  // a time. Uncommenting another breaks the program

  if(digitalRead(buttons[buttonRed]) == HIGH) {
    int old_index = red.get_index();
    writtenRed[old_index] = 1;
    myprint("Lighting location Red: ", old_index);
    // delay(500);
    light(red, CRGB::Red);

    while(writtenRed[red.get_index()]) {
      red.get_next_location();
      int new_index = red.get_index();
      myprint("trying new index: ", new_index);
      // delay(200);
      if (writtenRed[new_index]) { 
        myprint("Summing to ", old_index);
        // leds[new_index] += leds[old_index];
      }
    }
  }

  // if(digitalRead(buttons[buttonOrange]) == HIGH) {
  //   int old_index = orange.get_index();
  //   writtenOrange[old_index] = 1;
  //   myprint("Lighting location Orange: ", old_index);
  //   // delay(500);
  //   light(orange, 0x8CFF00);

  //   while(writtenOrange[orange.get_index()]) {
  //     orange.get_next_location();
  //     int new_index = orange.get_index();
  //     myprint("trying new index: ", new_index);
  //     // delay(200);
  //     if (writtenOrange[new_index]) { 
  //       myprint("Summing to ", old_index);
  //       // leds[new_index] += leds[old_index];
  //     }
  //   }
  // }

  if(digitalRead(buttons[buttonYellow]) == HIGH) {
    int old_index = yellow.get_index();
    writtenYellow[old_index] = 1;
    myprint("Lighting location Yellow: ", old_index);
    // delay(500);
    light(yellow, CRGB::Yellow);

    while(writtenYellow[yellow.get_index()]) {
      yellow.get_next_location();
      int new_index = yellow.get_index();
      myprint("trying new index: ", new_index);
      // delay(200);
      if (writtenYellow[new_index]) { 
        myprint("Summing to ", old_index);
        // leds[new_index] += leds[old_index];
      }
    }
  }

  // if(digitalRead(buttons[buttonGreen]) == HIGH) {
  //   int old_index = green.get_index();
  //   writtenGreen[old_index] = 1;
  //   myprint("Lighting location: ", old_index);
  //   // delay(500);
  //   light(green, CRGB::Green);

  //   while(writtenGreen[green.get_index()]) {
  //     green.get_next_location();
  //     int new_index = green.get_index();
  //     myprint("trying new index: ", new_index);
  //     // delay(200);
  //     if (writtenGreen[new_index]) { 
  //       myprint("Summing to ", old_index);
  //       // leds[new_index] += leds[old_index];
  //     }
  //   }
  // }

  // if(digitalRead(buttons[buttonBlue]) == HIGH) {
  //   int old_index = blue.get_index();
  //   writtenBlue[old_index] = 1;
  //   myprint("Lighting location Blue: ", old_index);
  //   // delay(500);
  //   light(blue, CRGB::Blue);

  //   while(writtenBlue[blue.get_index()]) {
  //     blue.get_next_location();
  //     int new_index = blue.get_index();
  //     myprint("trying new index: ", new_index);
  //     // delay(200);
  //     if (writtenBlue[new_index]) { 
  //       myprint("Summing to ", old_index);
  //       // leds[new_index] += leds[old_index];
  //     }
  //   }
  // }

  // if(digitalRead(buttons[buttonPurple]) == HIGH) {
  //   int old_index = purple.get_index();
  //   writtenPurple[old_index] = 1;
  //   myprint("Lighting location: ", old_index);
  //   // delay(500);
  //   light(purple, CRGB::Purple);

  //   while(writtenPurple[purple.get_index()]) {
  //     purple.get_next_location();
  //     int new_index = purple.get_index();
  //     myprint("trying new index: ", new_index);
  //     // delay(200);
  //     if (writtenPurple[new_index]) { 
  //       myprint("Summing to ", old_index);
  //       // leds[new_index] += leds[old_index];
  //     }
  //   }
  // }
  
}







