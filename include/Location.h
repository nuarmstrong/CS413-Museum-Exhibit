#ifndef LOCATION_H
#define LOCATION_H

#define COORD_MAX 16
#define COORD_MIN 0

#include <Arduino.h>

class Location {
  private:
    uint8_t x;
    uint8_t y;

  public:

    Location() : Location(random() % COORD_MAX, random() % COORD_MAX) { }

    Location(uint8_t x, uint8_t y) : x(x), y(y) { }

    ~Location() { }

    void get_next_location() {
        int dx = random(3) - 1; // -1, COORD_MIN, or 1
        int dy = random(3) - 1; // -1, COORD_MIN, or 1

        // Ensure that the move changes at least one coordinate.
        while(dx == COORD_MIN && dy == COORD_MIN){
            dx = random(3) - 1;
            dy = random(3) - 1;
        }

        // Check boundaries and adjust coordinates
        if(x + dx >= COORD_MIN && x + dx < COORD_MAX){
            x += dx;
        }

        if(y + dy >= COORD_MIN && y + dy < COORD_MAX){
            y += dy;
        }
    }

    // Calculate the index of the location in the 1D array
    // given the 2D coordinates.
    uint16_t get_index() {
      if (this->x & 0x01) {
          uint8_t reversedY = (COORD_MAX - 1) - y;
          return (x * COORD_MAX) + reversedY;
      } else {
          return (x * COORD_MAX) + y;
      }
    }
};

#endif // LOCATION_H
