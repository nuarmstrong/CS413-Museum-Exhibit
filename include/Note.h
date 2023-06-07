#ifndef NOTE_H
#define NOTE_H

#include <FastLED.h>
#include "Location.h"
#include "Bitset.h"

#define NUM_LEDS 1024
#define NUM_LEDS_PER_STRIP 256
#define MAX_LED_ON 20  // maximum number of LEDs on

class Note {
    private:
        const char label; // char signal for this note
        Location* loc; // pointer to a Location object
        BitSet written; // BitSet to keep track of which LEDs are on
        CRGB color; // color of this note
        CRGB (*leds)[NUM_LEDS];  // pointer to an array of NUM_LEDS CRGB objects
        uint16_t ring_buffer[MAX_LED_ON];  // ring buffer to store last MAX_LED_ON lit indexes
        uint8_t ring_buffer_index;  // index of the oldest element in the ring buffer

    public:

        Note(CRGB color, CRGB (*leds)[NUM_LEDS], const char ch)
        : color(color), leds(leds), label(ch), ring_buffer_index(0)
        {
            loc = new Location();
            for(uint8_t i = 0; i < MAX_LED_ON; i++)
                ring_buffer[i] = NUM_LEDS;  // initialize with an impossible index
        }

        // Free the memory allocated for the Location object
        ~Note() { delete loc; };

        // Light an LED and turn off the oldest LED if necessary
        void light_led() {
            uint16_t index = loc->get_index();

            // Add to ring buffer and turn off the oldest LED if necessary
            uint16_t oldest_led = ring_buffer[ring_buffer_index];

            if(oldest_led < NUM_LEDS) {
                (*leds)[oldest_led] -= color;  // emove color from the oldest LED
                (*leds)[oldest_led + (NUM_LEDS_PER_STRIP * 2)] -= color;
                (*leds)[oldest_led + (NUM_LEDS_PER_STRIP * 3)] -= color;
                (*leds)[oldest_led + (NUM_LEDS_PER_STRIP * 4)] -= color;
                written.clear(oldest_led);  // update the BitSet
            }

            ring_buffer[ring_buffer_index] = index;  // add new index to the buffer
            ring_buffer_index = (ring_buffer_index + 1) % MAX_LED_ON;  // move the index

            (*leds)[index] += color; // add color to the new LED
            (*leds)[index + (NUM_LEDS_PER_STRIP * 2)] += color;
            (*leds)[index + (NUM_LEDS_PER_STRIP * 3)] += color;
            (*leds)[index + (NUM_LEDS_PER_STRIP * 4)] += color;

            FastLED.show();
            delay(20);
        }

        // Draw a line of LEDs
        void draw_line() {
            written.set(loc->get_index());
            light_led();
            while(written.get(loc->get_index())) { 
                loc->get_next_location(); 
            }
        }

        // Verify if the character matches the label 
        // when signal is received from MIDI 
        void verify(char c) {
          if (c == label) draw_line();
        }
};
#endif // NOTE_H