#ifndef NOTE_H
#define NOTE_H

#include <FastLED.h>
#include "Location.h"

#define NUM_LEDS 256

enum button {
  buttonRed = 12,
  buttonOrange = 11,
  buttonYellow = 10,
  buttonGreen = 6,
  buttonBlue = 5,
  buttonPurple = 4,
};

class Note {
    private:
        Location* loc;
        bool written[256] = {false};
        CRGB color;
        CRGB (*leds)[256];  // pointer to an array of 256 CRGB

    public:

        Note(CRGB color, CRGB (*leds)[256])
        : color(color), leds(leds) 
        {
            this->loc = new Location();
        }

        ~Note() {
            delete this->loc;
         };

        void draw_px() {
            uint16_t index = this->loc->get_index();
            (*leds)[index] += this->color;
            FastLED.show();
            delay(50);
        }

        void draw_line() {
            written[this->loc->get_index()] = true;
            draw_px();
            while(written[this->loc->get_index()]) {
                this->loc->get_next_location();
            }
        }
    
};
#endif // NOTE_H