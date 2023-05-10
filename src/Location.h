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
    static const int X = 0;
    static const int Y = 1;

  Location() : Location(random() % 16, random() % 16) { }

  Location(uint8_t x, uint8_t y) : x(x), y(y) { }

  ~Location() { }

  void inc(const int y) {
    if (y) {
        this->y = (y < COORD_MAX) ? this->y + 1 : this->y;
    } else {
        this->x = (y < COORD_MAX) ? this->x + 1 : this->x;
    }
  }

  void dec(const int y) {
    if (y) {
        this->y = (y > COORD_MIN) ? this->y - 1 : this->y;
    } else {
        this->x = (x > COORD_MIN) ? this->x - 1 : this->x;
    }
  }

  int pick_legal_move(int* arr, int size) {
    int index = random(0, size);
    return *(arr + index);
  }

  void get_next_location() {

    int pick;

    if ((this->x == COORD_MAX) && (this->y == COORD_MAX)) {
      int rand[] = {1,4,6};
      pick = pick_legal_move(rand, 3);
      }
    else if ((this->x == COORD_MIN) && (this->y == COORD_MIN)) { 
      int rand[] = {2,4,5};
      pick = pick_legal_move(rand, 3);
      }
    else if ((this->x == COORD_MIN) && (this->y == COORD_MAX)) { 
      int rand[] = {1,3,7};
      pick = pick_legal_move(rand, 3);
      }
    else if ((this->x == COORD_MAX) && (this->y == COORD_MIN)) { 
      int rand[] = {2,4,5};
      pick = pick_legal_move(rand, 3);
      }
    else if (this->x == COORD_MIN)                            { 
      int rand[] = {1,2,3,7,8};
      pick = pick_legal_move(rand, 5);
      }
    else if (this->x == COORD_MAX)                            { 
      int rand[] = {1,2,4,5,6};
      pick = pick_legal_move(rand, 5);
      }
    else if (this->y == COORD_MIN)                            { 
      int rand[] = {2,3,4,5,8};
      pick = pick_legal_move(rand, 5);
      }
    else if (this->y == COORD_MAX)                            { 
      int rand[] = {1,3,4,6,7};
      pick = pick_legal_move(rand, 5);
      }
    else                                                     { 
      int rand[] = {1,2,3,4,5,6,7,8};
      pick = pick_legal_move(rand, 8);
      }


  switch (pick) {
    case 1:
        // x, y-  
        this->dec(Location::Y);
        break;
    case 2:
        // x, y+
        this->inc(Location::Y);
        break;
    case 3:
        // x+, y0
        this->inc(Location::X);
        break;
    case 4:
        // x-, y0
        this->dec(Location::X);
        
        break;
    case 5:
        // x-, y+
        this->dec(Location::X);
        this->inc(Location::Y);
        break;
    case 6:
        // x-, y-
        this->dec(Location::X);
        this->dec(Location::Y);
        break;
    case 7:
        // x+, y-
        this->inc(Location::X);
        this->dec(Location::Y);
        break;
    default:
        // x+, y+
        this->inc(Location::X);
        this->inc(Location::Y);
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
