#include <FastLED.h>
#include "Location.h"
#include "Note.h"

#define NUM_LEDS 768
#define DATA_PIN 11

const byte numChars = 200;
char receivedChars[numChars]; 
CRGB leds[NUM_LEDS];

Note C3 = Note(0x12EE12, &leds);
Note D3b = Note(0x7CF42F, &leds);
Note D3 = Note(0xE9EC4F, &leds);
Note E3b = Note(0xC48C3F, &leds, 'd');
Note E3 = Note(0xBE6C44, &leds, 'e');
Note F3 = Note(0xC06B7B, &leds, 'f');

Note G3b = Note(0xC967D4, &leds, 'g');
Note G3 = Note(0x7735BE, &leds, 'h');
Note A3b = Note(0x5626A5, &leds, 'i');
Note A = Note(0x4F5CA2, &leds, 'j');
Note B3b = Note(0x5AA6A4, &leds, 'k');
Note B3 = Note(0x2FEE7E, &leds, 'l');

Note C4 = Note(CRGB::Red, &leds, 'm');
Note D4b = Note(0x7CF42F, &leds, 'n');
Note D4 = Note(CRGB::Blue, &leds, 'o');
Note E4b = Note(0xC48C3F, &leds, 'p');
Note E4 = Note(0xBE6C44, &leds, 'q');
Note F4 = Note(0xC06B7B, &leds, 'r');
Note G4b = Note(0xC967D4, &leds, 's');
Note G4 = Note(0x7735BE, &leds, 't');
Note A4b = Note(0x5626A5, &leds, 'u');
Note AFour = Note(0x4F5CA2, &leds, 'v');
Note B4b = Note(0x5AA6A4, &leds, 'w');
Note B4 = Note(0x2FEE7E, &leds, 'x');

Note C5 = Note(0x12EE12, &leds, 'y');
boolean newData = false;

void setup() {
  FastLED.addLeds<WS2812,DATA_PIN,RGB>(leds,NUM_LEDS);
  FastLED.setBrightness(5);
  randomSeed(analogRead(0));
  Serial.begin(9600);
  FastLED.clear();
  FastLED.show();
}

void(* resetFunc) (void) = 0;

void recvWithEndMarker() {
    static byte ndx = 0;
    char endMarker = '\n';
    char rc;
    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (rc != endMarker) {
            receivedChars[ndx] = rc;
            ndx++;
            if (ndx >= numChars) {
                ndx = 0;
            }
        }
        else {
            receivedChars[ndx] = '\0'; // terminate the string
            ndx = 0;
            newData = true;
        }
    }
  bool switch1 = false;
  bool switch2 = false;
  bool switch3 = false;
  bool switch4 = false;
  bool switch5 = false;
  bool switch6 = false;
  bool switch7 = false;
  bool switch8 = false;
  bool switch9 = false;
  bool switch10 = false;
  bool switch11 = false;
  bool switch12 = false;
  bool switch13 = false;
  bool switch14 = false;
  bool switch15 = false;
  bool switch16 = false;
  bool switch17 = false;
  bool switch18 = false;
  bool switch19 = false;
  bool switch20 = false;
  bool switch21 = false;
  bool switch22 = false;
  bool switch23 = false;
  bool switch24 = false;
  bool switch25 = false;
  for (int jj = 0; jj < 200; jj++) {
      if (receivedChars[jj] == 'A') {
        switch1 = true;
      } 
      else if (receivedChars[jj] == 'B') {
        switch2 = true;
      }
      else if (receivedChars[jj] == 'C') {
        switch3 = true;
      } 
      else if (receivedChars[jj] == 'D') {
        switch4 = true;
      }
      else if (receivedChars[jj] == 'E') {
        switch5 = true;
      } 
      else if (receivedChars[jj] == 'F') {
        switch6 = true;
      }
      else if (receivedChars[jj] == 'G') {
        switch7 = true;
      } 
      else if (receivedChars[jj] == 'H') {
        switch8 = true;
      }
      else if (receivedChars[jj] == 'I') {
        switch9 = true;
      } 
      else if (receivedChars[jj] == 'J') {
        switch10 = true;
      }
      else if (receivedChars[jj] == 'K') {
        switch11 = true;
      } 
      else if (receivedChars[jj] == 'L') {
        switch12 = true;
      }
      else if (receivedChars[jj] == 'M') {
        switch13 = true;
      } 
      else if (receivedChars[jj] == 'N') {
        switch14 = true;
      }
      else if (receivedChars[jj] == 'O') {
        switch15 = true;
      } 
      else if (receivedChars[jj] == 'P') {
        switch16 = true;
      }
      else if (receivedChars[jj] == 'Q') {
        switch17 = true;
      }
      else if (receivedChars[jj] == 'R') {
        switch18 = true;
      } 
      else if (receivedChars[jj] == 'S') {
        switch19 = true;
      }
      else if (receivedChars[jj] == 'T') {
        switch20 = true;
      } 
      else if (receivedChars[jj] == 'U') {
        switch21 = true;
      }
      else if (receivedChars[jj] == 'V') {
        switch22 = true;
      } 
      else if (receivedChars[jj] == 'W') {
        switch23 = true;
      }
      else if (receivedChars[jj] == 'X') {
        switch24 = true;
      } 
      else if (receivedChars[jj] == 'Y') {
        switch25 = true;
      }
      else if (receivedChars[jj] == 'Z') {
        resetFunc();
      }
  }
  for (int jj = 0; jj < 200; jj++) {
      if (receivedChars[jj] == 'a' && switch1) {
        receivedChars[jj] = "";
      } 
      if (receivedChars[jj] == 'b' && switch2) {
        receivedChars[jj] = "";
      }
      if (receivedChars[jj] == 'A' && switch1) {
        receivedChars[jj] = "";
      } 
      if (receivedChars[jj] == 'B' && switch2) {
        receivedChars[jj] = "";
      }
      if (receivedChars[jj] == 'c' && switch3) {
        receivedChars[jj] = "";
      } 
      if (receivedChars[jj] == 'd' && switch4) {
        receivedChars[jj] = "";
      }
      if (receivedChars[jj] == 'C' && switch3) {
        receivedChars[jj] = "";
      } 
      if (receivedChars[jj] == 'D' && switch4) {
        receivedChars[jj] = "";
      }
      if (receivedChars[jj] == 'e' && switch5) {
        receivedChars[jj] = "";
      } 
      if (receivedChars[jj] == 'f' && switch6) {
        receivedChars[jj] = "";
      }
      if (receivedChars[jj] == 'E' && switch5) {
        receivedChars[jj] = "";
      } 
      if (receivedChars[jj] == 'F' && switch6) {
        receivedChars[jj] = "";
      }
      if (receivedChars[jj] == 'g' && switch7) {
        receivedChars[jj] = "";
      } 
      if (receivedChars[jj] == 'h' && switch8) {
        receivedChars[jj] = "";
      }
      if (receivedChars[jj] == 'G' && switch7) {
        receivedChars[jj] = "";
      } 
      if (receivedChars[jj] == 'H' && switch8) {
        receivedChars[jj] = "";
      }
      if (receivedChars[jj] == 'i' && switch9) {
        receivedChars[jj] = "";
      } 
      if (receivedChars[jj] == 'j' && switch10) {
        receivedChars[jj] = "";
      }
      if (receivedChars[jj] == 'I' && switch9) {
        receivedChars[jj] = "";
      } 
      if (receivedChars[jj] == 'J' && switch10) {
        receivedChars[jj] = "";
      }
      if (receivedChars[jj] == 'k' && switch11) {
        receivedChars[jj] = "";
      } 
      if (receivedChars[jj] == 'l' && switch12) {
        receivedChars[jj] = "";
      }
      if (receivedChars[jj] == 'K' && switch11) {
        receivedChars[jj] = "";
      } 
      if (receivedChars[jj] == 'L' && switch12) {
        receivedChars[jj] = "";
      }
      if (receivedChars[jj] == 'm' && switch13) {
        receivedChars[jj] = "";
      } 
      if (receivedChars[jj] == 'n' && switch14) {
        receivedChars[jj] = "";
      }
      if (receivedChars[jj] == 'M' && switch13) {
        receivedChars[jj] = "";
      } 
      if (receivedChars[jj] == 'N' && switch14) {
        receivedChars[jj] = "";
      }
      if (receivedChars[jj] == 'o' && switch15) {
        receivedChars[jj] = "";
      } 
      if (receivedChars[jj] == 'p' && switch16) {
        receivedChars[jj] = "";
      }
      if (receivedChars[jj] == 'O' && switch15) {
        receivedChars[jj] = "";
      } 
      if (receivedChars[jj] == 'P' && switch16) {
        receivedChars[jj] = "";
      }
      if (receivedChars[jj] == 'q' && switch17) {
        receivedChars[jj] = "";
      } 
      if (receivedChars[jj] == 'r' && switch18) {
        receivedChars[jj] = "";
      }
      if (receivedChars[jj] == 'Q' && switch17) {
        receivedChars[jj] = "";
      } 
      if (receivedChars[jj] == 'R' && switch18) {
        receivedChars[jj] = "";
      }
      if (receivedChars[jj] == 's' && switch19) {
        receivedChars[jj] = "";
      } 
      if (receivedChars[jj] == 't' && switch20) {
        receivedChars[jj] = "";
      }
      if (receivedChars[jj] == 'S' && switch19) {
        receivedChars[jj] = "";
      } 
      if (receivedChars[jj] == 'T' && switch20) {
        receivedChars[jj] = "";
      }
      if (receivedChars[jj] == 'u' && switch21) {
        receivedChars[jj] = "";
      } 
      if (receivedChars[jj] == 'v' && switch22) {
        receivedChars[jj] = "";
      }
      if (receivedChars[jj] == 'U' && switch21) {
        receivedChars[jj] = "";
      } 
      if (receivedChars[jj] == 'V' && switch22) {
        receivedChars[jj] = "";
      }
      if (receivedChars[jj] == 'w' && switch23) {
        receivedChars[jj] = "";
      } 
      if (receivedChars[jj] == 'x' && switch24) {
        receivedChars[jj] = "";
      }
      if (receivedChars[jj] == 'W' && switch23) {
        receivedChars[jj] = "";
      } 
      if (receivedChars[jj] == 'X' && switch24) {
        receivedChars[jj] = "";
      }
      if (receivedChars[jj] == 'y' && switch25) {
        receivedChars[jj] = "";
      }
      if (receivedChars[jj] == 'Y' && switch25) {
        receivedChars[jj] = "";
      } 
  }
}

void loop() {
  recvWithEndMarker();
    for (char c : receivedChars) {
          C3.verify(c);
          D3b.verify(c);
          D3.verify(c);
          E3b.verify(c);
          E3.verify(c);
          F3.verify(c);
          G3b.verify(c);
          G3.verify(c);
          A3b.verify(c);
          A.verify(c);
          B3b.verify(c);
          B3.verify(c);
          C4.verify(c);
          D4b.verify(c);
          D4.verify(c);
          E4b.verify(c);
          E4.verify(c);
          F4.verify(c);
          G4b.verify(c);
          G4.verify(c);
          A4b.verify(c);
          AFour.verify(c);
          B4b.verify(c);
          B4.verify(c);
          C5.verify(c);
    } 
}