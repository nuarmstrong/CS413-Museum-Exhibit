#ifndef NOTE_H
#define NOTE_H

#include <FastLED.h>
#include "Location.h"

#define NUM_LEDS 256

enum button {
  buttonRed,
  buttonOrange,
  buttonYellow,
  buttonGreen,
  buttonBlue,
  buttonPurple,
};
const int buttons[6] = {12, 11, 10, 6, 5, 4};

class Note {
    private:
        Location* loc;
        bool written[256] = {};
        String fpath;
        uint8_t pin;
        button b;
        unsigned int color;
        unsigned int* leds;
        CRGB leds[NUM_LEDS] = {};


    public:

        Note(Location* loc, String fpath, uint8_t pin, button b, unsigned int color) {

            this->loc = loc;
            this->fpath = fpath;
            this->pin = pin;
            pinMode(pin, INPUT);
            this->b = b;
            this->color = color;

         }

        ~Note() { };

        bool pushed() { return digitalRead(buttons[color]) == HIGH; }

        void draw_px(unsigned int color) {
            uint16_t index = this->loc->get_index();
            leds[index] += color;
            FastLED.show();
            // if (d) delay(50);
        }

        void draw(unsigned int color) {
            if(pushed) {
                int old_index = this->loc->get_index();
                written[old_index] = 1;
                this->draw_px(color);

                while(written[old_index]) { // maybe err
                    this->loc->get_next_location();
                    int new_index = this->loc->get_index();
                }
            }
        }

    
};
#endif // NOTE_H