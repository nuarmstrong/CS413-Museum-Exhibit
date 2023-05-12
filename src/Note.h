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
        // const char path;
        uint8_t pin;
        bool written[256] = {false};
        CRGB color;
        CRGB (*leds)[256];  // pointer to an array of 256 CRGB

    public:

        Note(button pin_num, CRGB color, CRGB (*leds)[256])
        : pin(pin_num), color(color), leds(leds) 
        {
            this->loc = new Location(random() % 16, random() % 16);
            pinMode(pin_num, INPUT);
        }

        ~Note() { };

        void draw_px() {
            uint16_t index = this->loc->get_index();
            (*leds)[index] += this->color;
            FastLED.show();
            delay(50);
        }

        bool pushed() { return digitalRead(this->pin) == HIGH; }

        void draw_line() {
            written[this->loc->get_index()] = true;
            draw_px();
            while(written[this->loc->get_index()]) {
                this->loc->get_next_location();
            }
        }

    
};
#endif // NOTE_H