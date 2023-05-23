#ifndef NOTE_H
#define NOTE_H

#include <FastLED.h>
#include "Location.h"
#include "Bitset.h"

#define NUM_LEDS 256

enum button {
  buttonRed = 12,
  buttonOrange = 11,
  buttonYellow = 10,
  buttonGreen = 6,
  buttonBlue = 8,
  buttonPurple = 4,
};

class Note {
    private:
        Location* loc;
        BitSet written;
        uint8_t pin;
        CRGB color;
        CRGB (*leds)[256];  // pointer to an array of 256 CRGB

    public:

        Note(button pin_num, CRGB color, CRGB (*leds)[256])
        : pin(pin_num), color(color), leds(leds) 
        {
            this->loc = new Location();
            pinMode(pin_num, INPUT);
        }

        ~Note() {
            delete this->loc;
        };

        bool pushed() { return digitalRead(this->pin) == HIGH; }

        void draw_px() {
            uint16_t index = this->loc->get_index();
            (*leds)[index] += this->color;
            FastLED.show();
            delay(50);
        }

        void draw_line() {
            written.set(this->loc->get_index());
            draw_px();
            while(written.get(this->loc->get_index()) != 0) {
                this->loc->get_next_location();
            }
        }
    
};
#endif // NOTE_H