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
    static const int rand1[] = {1, 4, 6};
    static const int rand2[] = {2, 4, 5};
    static const int rand3[] = {1, 3, 7};
    static const int rand4[] = {1, 2, 3, 7, 8};
    static const int rand5[] = {1, 2, 4, 5, 6};
    static const int rand6[] = {2, 3, 4, 5, 8};
    static const int rand7[] = {1, 3, 4, 6, 7};
    static const int rand8[] = {1, 2, 3, 4, 5, 6, 7, 8};

    const int *rand;
    int size;

    if ((this->x == COORD_MAX) && (this->y == COORD_MAX)) {
        rand = rand1;
        size = 3;
    } else if ((this->x == COORD_MIN) && (this->y == COORD_MIN)) {
        rand = rand2;
        size = 3;
    } else if ((this->x == COORD_MIN) && (this->y == COORD_MAX)) {
        rand = rand3;
        size = 3;
    } else if ((this->x == COORD_MAX) && (this->y == COORD_MIN)) {
        rand = rand2;
        size = 3;
    } else if (this->x == COORD_MIN) {
        rand = rand4;
        size = 5;
    } else if (this->x == COORD_MAX) {
        rand = rand5;
        size = 5;
    } else if (this->y == COORD_MIN) {
        rand = rand6;
        size = 5;
    } else if (this->y == COORD_MAX) {
        rand = rand7;
        size = 5;
    } else {
        rand = rand8;
        size = 8;
    }

    int pick = rand[random(size)];

    switch (pick) {
        case 1: // x, y-
            this->y--;
            break;
        case 2: // x, y+
            this->y++;
            break;
        case 3: // x+, y0
            this->x++;
            break;
        case 4: // x-, y0
            this->x--;
            break;
        case 5: // x-, y+
            this->x--;
            this->y++;
            break;
        case 6: // x-, y-
            this->x--;
            this->y--;
            break;
        case 7: // x+, y-
            this->x++;
            this->y--;
            break;
        default: // x+, y+
            this->x++;
            this->y++;
            break;
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
