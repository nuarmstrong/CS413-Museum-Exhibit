#include <Arduino.h>
#include <FastLED.h>
#include "Location.h"
#include "Note.h"

#define NUM_LEDS 256
#define DATA_PIN 11

// const int rs = 9, en = 8, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
// LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

enum keys {
    NOTE_C3 = 48,
    NOTE_D3b = 49,
    NOTE_D3 = 50,
    NOTE_E3b = 51,
    NOTE_E3 = 52,
    NOTE_F3 = 53,
    NOTE_G3b = 54,
    NOTE_G3 = 55,
    NOTE_A3b = 56,
    NOTE_A3 = 57,
    NOTE_B3b = 58,
    NOTE_B3 = 59,
    NOTE_C4 = 60,
    NOTE_D4b = 61,
    NOTE_D4 = 62,
    NOTE_E4b = 63,
    NOTE_E4 = 64,
    NOTE_F4 = 65,
    NOTE_G4b = 66,
    NOTE_G4 = 67,
    NOTE_A4b = 68,
    NOTE_A4 = 69,
    NOTE_B4b = 70,
    NOTE_B4 = 71,
    NOTE_C5 = 72,
};

CRGB leds[NUM_LEDS];

Note C3 = Note( 0x2DEE28, &leds);
Note D3b = Note( 0x7CF42F, &leds);
Note D3 = Note( 0xE9EC4F, &leds);
Note E3b = Note( 0xC48C3F, &leds);
Note E3 = Note( 0xBE6C44, &leds);
Note F3 = Note( 0xC06B7B, &leds);

Note G3b = Note(0xC967D4, &leds);
Note G3 = Note(0x7735BE, &leds);
Note A3b = Note(0x5626A5, &leds);
Note A = Note(0x4F5CA2, &leds);
Note B3b = Note(0x5AA6A4, &leds);
Note B3 = Note(0x2FEE7E, &leds);

Note C4 = Note(0x2DEE28, &leds);
Note D4b = Note(0x7CF42F, &leds);
Note D4 = Note(0xE9EC4F, &leds);
Note E4b = Note(0xC48C3F, &leds);
Note E4 = Note(0xBE6C44, &leds);
Note F4 = Note(0xC06B7B, &leds);
Note G4b = Note(0xC967D4, &leds);
Note G4 = Note(0x7735BE, &leds);
Note A4b = Note(0x5626A5, &leds);
Note AFour = Note(0x4F5CA2, &leds);
Note B4b = Note(0x5AA6A4, &leds);
Note B4 = Note(0x2FEE7E, &leds);
Note C5 = Note(0x2DEE28, &leds);


void setup() { 

  randomSeed(analogRead(0));
  Serial.begin(9600);
  
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
  FastLED.setBrightness(2);
  FastLED.clear();
}


void loop() { 
  // lcd.clear();
  char rc, rc2; 

  // receiveEvent();

  // for (int i = 0; i < 64; i+=2) {
  //   int x = (recv[i] << 8) | recv[i+1];
  //   switch (x) {
  //     case 0x30:
  //       A.draw_line();
  //       break;
  //     default:
  //       break;
  //   }
  // }


  if ((Serial.available() >= 2) && (newData == false)) {
    rc = Serial.read();
    rc2 = Serial.read();
    int x = (rc << 8) | rc2;
    // if (x == 0x30) {
    //   // lcd.print(rc);
    //   // delay(2000);
    //   C3.draw_line();
    // } 
    // else if (x == -48) {
    //   F.draw_line();
    // }

    switch (x) {
      case NOTE_C3:
        C3.draw_line();
        break;
      case 49:
        D3b.draw_line();
        break;
      case 50:
        D3.draw_line();
        break;
      case 51:
        E3b.draw_line();
        break;
      case 52:
        E3.draw_line();
        break;
      case 53:
        F3.draw_line();
        break;
      case NOTE_G3b:
        G3b.draw_line();
        break;
      case NOTE_G3:
        G3.draw_line();
        break;
      case NOTE_A3b:
        A3b.draw_line();
        break;
      case NOTE_A3:
        A.draw_line();
        break;
      case NOTE_B3b:
        B3b.draw_line();
        break;
      case NOTE_B3:
        B3.draw_line();
        break;
      case NOTE_C4:
        C4.draw_line();
        break;
      case NOTE_D4b:
        D4b.draw_line();
        break;
      case NOTE_D4:
        D4.draw_line();
        break;
      case NOTE_E4b:
        E4b.draw_line();
        break;
      case NOTE_E4:
        E4.draw_line();
        break;
      case NOTE_F4:
        F4.draw_line();
        break;
      case NOTE_G4b:
        G4b.draw_line();
        break;
      case NOTE_G4:
        G4.draw_line();
        break;
      case NOTE_A4b:
        A4b.draw_line();
        break;
      case NOTE_A4:
        AFour.draw_line();
        break;
      case NOTE_B4b:
        B4b.draw_line();
        break;
      case NOTE_B4:
        B4.draw_line();
        break;
      case NOTE_C5:
        C5.draw_line();
        break;
      default:
        break;
    }
  }

  // if(A.pushed()) A.draw_line();
  // if(B.pushed()) B.draw_line();
  // if(C.pushed()) C.draw_line();
  // if(D.pushed()) D.draw_line();
  // if(E.pushed()) E.draw_line();
  // if(F.pushed()) F.draw_line();

}







