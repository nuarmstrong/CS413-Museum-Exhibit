// #ifndef NOTE_H
// #define NOTE_H

// #include <FastLED.h>
// #include "Location.h"
// #include "Bitset.h"

// #define NUM_LEDS 256

// enum button {
//   buttonRed = 12,
//   buttonOrange = 11,
//   buttonYellow = 10,
//   buttonGreen = 6,
//   buttonBlue = 5,
//   buttonPurple = 4,
// };

// class Note {
//     private:
//         Location* loc;
//         uint8_t pin;
//         BitSet written;
//         CRGB color;
//         CRGB (*leds)[256];  // pointer to an array of 256 CRGB

//     public:

//         Note(button pin_num, CRGB color, CRGB (*leds)[256])
//         : pin(pin_num), color(color), leds(leds) 
//         {
//             this->loc = new Location(random(16), random(16));
//             pinMode(pin_num, INPUT);
//         }

//         ~Note() { };

//         void draw_px() {
//             uint16_t index = this->loc->get_index();
//             (*leds)[index] += this->color;
//             FastLED.show();
//             delay(50);
//         }

//         bool pushed() { return digitalRead(this->pin) == HIGH; }

//         void draw_line() {
//             written.set(this->loc->get_index());
//             draw_px();
//             while(written.get(this->loc->get_index())) {
//                 this->loc->get_next_location();
//             }
//         }

    
// };
// #endif // NOTE_H

#ifndef NOTE_H
#define NOTE_H

#include <FastLED.h>
#include "Location.h"
#include "Bitset.h"

#define NUM_LEDS 1024
#define MAX_LED_ON 20  // maximum number of LEDs on


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
        uint8_t pin;
        BitSet written;
        CRGB color;
        CRGB (*leds)[NUM_LEDS];  // pointer to an array of 256 CRGB
        uint16_t ring_buffer[MAX_LED_ON];  // ring buffer to store last MAX_LED_ON lit indexes
        uint8_t ring_buffer_index;  // index of the oldest element in the ring buffer


    public:

        Note(button pin_num, CRGB color, CRGB (*leds)[NUM_LEDS])
        : pin(pin_num), color(color), leds(leds), ring_buffer_index(0)
        {
            this->loc = new Location(random(16), random(16));
            pinMode(pin_num, INPUT);
            for(uint8_t i = 0; i < MAX_LED_ON; i++)
                ring_buffer[i] = NUM_LEDS;  // initialize with an impossible index
        }

        ~Note() { };

        void draw_px() {
            uint16_t index = this->loc->get_index();

            // Add to ring buffer and turn off the oldest LED if necessary
            uint16_t oldest_led = ring_buffer[ring_buffer_index];
            if(oldest_led < NUM_LEDS) {
                (*leds)[oldest_led] -= this->color;  // turn off the oldest LED
                (*leds)[oldest_led+256] -= this->color;
                (*leds)[oldest_led+512] -= this->color;
                (*leds)[oldest_led+768] -= this->color;
                written.clear(oldest_led);  // update the BitSet
            }

            ring_buffer[ring_buffer_index] = index;  // add new index to the buffer
            ring_buffer_index = (ring_buffer_index + 1) % MAX_LED_ON;  // move the index

            (*leds)[index] += this->color;
            (*leds)[index+256] += this->color;
            (*leds)[index+512] += this->color;
            (*leds)[index+768] += this->color;
            FastLED.show();
            delay(20);
        }

        bool pushed() { return digitalRead(this->pin) == HIGH; }

        void draw_line() {
            written.set(this->loc->get_index());
            draw_px();
            while(written.get(this->loc->get_index())) {
                this->loc->get_next_location();
            }
        }

    
};
#endif // NOTE_H