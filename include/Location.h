#ifndef LOCATION_H
#define LOCATION_H

#define COORD_MAX 15
#define COORD_MIN 0

#include <Arduino.h>

class Location {
  private:
    uint8_t x;
    uint8_t y;

  public:

    Location() : Location(random() % 16, random() % 16) { }

    Location(uint8_t x, uint8_t y) : x(x), y(y) { }

    ~Location() { }

    void get_next_location() {
        int dx = random(3) - 1; // -1, 0, or 1
        int dy = random(3) - 1; // -1, 0, or 1

        // Ensure that the move changes at least one coordinate.
        while(dx == 0 && dy == 0){
            dx = random(3) - 1;
            dy = random(3) - 1;
        }

        // Check boundaries and adjust coordinates
        if(x + dx >= 0 && x + dx < 16){
            x += dx;
        }

        if(y + dy >= 0 && y + dy < 16){
            y += dy;
        }
    }

    uint16_t get_index() {
      if (this->x & 0x01) {
          uint8_t reversedY = (16 - 1) - y;
          return (x * 16) + reversedY;
      } else {
          return (x * 16) + y;
      }
    }
};

#endif // LOCATION_H
