#include <Arduino.h>
#include <FastLED.h>
#include "Location.h"

#define NUM_LEDS 256
#define DATA_PIN 3
#define PRINT_ENABLED false
enum button {
  buttonRed,
  buttonOrange,
  buttonYellow,
  buttonGreen,
  buttonBlue,
  buttonPurple,
};
const int buttons[6] = {12, 11, 10, 6, 5, 4};

CRGB leds[NUM_LEDS];
bool writtenRed[256];
bool writtenOrange[256];
bool writtenYellow[256];
bool writtenGreen[256];
bool writtenBlue[256];
bool writtenPurple[256];

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

void light(Location loc, CRGB color, bool d = true) {

  uint16_t index = loc.get_index();
  // CRGB new_color = static_cast<CRGB>(color + leds[color]);
  // myprint("Summing ", new_color);
  // myprint("to ", leds[index]);
  leds[index] += color;
  FastLED.show();
  if (d) delay(50);

}

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

int i = 0;

void loop() { 

  // if(digitalRead(buttons[buttonRed]) == HIGH) {
  //   Serial.print("on");
  // }

  if(digitalRead(buttons[buttonRed]) == HIGH) {
    int old_index = red.get_index();
    writtenRed[old_index] = 1;
    myprint("Lighting location Red: ", old_index);
    // delay(500);
    light(red, CRGB::Green);

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
  //   light(orange, 0xA5FF00);

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

  // if(digitalRead(buttons[buttonGreen]) == HIGH) {
  //   int old_index = green.get_index();
  //   writtenGreen[old_index] = 1;
  //   myprint("Lighting location: ", old_index);
  //   // delay(500);
  //   light(green, CRGB::Red);

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

  if(digitalRead(buttons[buttonBlue]) == HIGH) {
    int old_index = blue.get_index();
    writtenBlue[old_index] = 1;
    myprint("Lighting location Blue: ", old_index);
    // delay(500);
    light(blue, CRGB::Blue);

    while(writtenBlue[blue.get_index()]) {
      blue.get_next_location();
      int new_index = blue.get_index();
      myprint("trying new index: ", new_index);
      // delay(200);
      if (writtenBlue[new_index]) { 
        myprint("Summing to ", old_index);
        // leds[new_index] += leds[old_index];
      }
    }
  }

  // if(digitalRead(buttons[buttonPurple]) == HIGH) {
  //   int old_index = purple.get_index();
  //   writtenPurple[old_index] = 1;
  //   myprint("Lighting location: ", old_index);
  //   // delay(500);
  //   light(purple, 0x00FFFF);

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







