#include "Location.h"

#define COORD_MAX 15
#define COORD_MIN 0

class Location
{
private:
  uint8_t x;
  uint8_t y;
public:

  static const int X = 0;
  static const int Y = 1;

  Location::Location(uint8_t x, uint8_t y) {
    this->x = x;
    this->y = y;
  }

  Location::~Location() { }

  void Location::inc(const int y) {
    if (y) {
      // this->y = this->y + 1;
      this->y = (y < COORD_MAX) ? this->y + 1 : this->y;
    } else {
      // this->x = this-> x + 1;
      this->x = (y < COORD_MAX) ? this->x + 1 : this->x;
    }
  }

  void Location::dec(const int y) {
    if (y) {
      // this->y = this->y - 1;
      this->y = (y > COORD_MIN) ? this->y - 1 : this->y;
    } else {
      // this->x = this-> x - 1;
      this->x = (x > COORD_MIN) ? this->x - 1 : this->x;
    }
  }

  void Location::get_next_location() {

    int rand = random(1, 5);

    // TODO: Figure out this nonsense

    // int find_legal_move(int* arr) {
    //     int index = random(0, sizeof(rand) / sizeof(int));
    //     return *(arr + index);
    //   }

    //   void get_next_location() {

    //     int pick = random(1, 9);

    //     int curr_x = this->x;
    //     int curr_y = this->y;
    //     // int pick;

    //     // if      ((curr_x == COORD_MAX) && (curr_y == COORD_MAX)) {
    //     //   int rand[] = {1,4,6};
    //     //   pick = find_legal_move(rand);
    //     //   }
    //     // else if ((curr_x == COORD_MIN) && (curr_y == COORD_MIN)) { 
    //     //   int rand[] = {2,4,5};
    //     //   pick = find_legal_move(rand);
    //     //   }
    //     // else if ((curr_x == COORD_MIN) && (curr_y == COORD_MAX)) { 
    //     //   int rand[] = {1,3,7};
    //     //   pick = find_legal_move(rand);
    //     //   }
    //     // else if ((curr_x == COORD_MAX) && (curr_y == COORD_MIN)) { 
    //     //   int rand[] = {2,4,5};
    //     //   pick = find_legal_move(rand);
    //     //   }
    //     // else if (curr_x == COORD_MIN)                            { 
    //     //   int rand[] = {1,2,3,7,8};
    //     //   pick = find_legal_move(rand);
    //     //   }
    //     // else if (curr_x == COORD_MAX)                            { 
    //     //   int rand[] = {1,2,4,5,6};
    //     //   pick = find_legal_move(rand);
    //     //   }
    //     // else if (curr_y == COORD_MIN)                            { 
    //     //   int rand[] = {2,3,4,5,8};
    //     //   pick = find_legal_move(rand);
    //     //   }
    //     // else if (curr_y == COORD_MAX)                            { 
    //     //   int rand[] = {1,3,4,6,7};
    //     //   pick = find_legal_move(rand);
    //     //   }
    //     // else                                                     { 
    //     //   int rand[] = {1,2,3,4,5,6,7,8};
    //     //   pick = find_legal_move(rand);
    //     //   }


    switch (rand) // REORGANIZE THESE BASED ON NOTEBOOK
    {
    case 1:
      // x+, y+
      if (this->x < COORD_MAX) this->inc(Location::X);
      if (this->y < COORD_MAX) this->inc(Location::Y);
      break;
    case 2:
      // x+, y-
      if (this->x < COORD_MAX) this->inc(Location::X);
      if (this->y > COORD_MIN) this->dec(Location::Y);
      break;
    case 3:
      // x+, y0
      this->inc(Location::X);
      break;
    case 4:
      // x-, y+
      if (this->x > COORD_MIN) this->dec(Location::X);
      if (this->y < COORD_MAX) this->inc(Location::Y);
      break;
    case 5:
      // x-, y-
      if (this->x > COORD_MIN) this->dec(Location::X);
      if (this->y > COORD_MIN) this->dec(Location::Y);
      break;
    case 6:
      // x-, y0
      this->dec(Location::X);
      break;
    case 7:
      // x, y+
      this->inc(Location::Y);
      break;
    default:
      // x, y-
      this->dec(Location::Y);
      break;
    }
  }

  uint16_t Location::get_index() {
    if (this->y & 0x01) {
      uint8_t reversedX = (16 - 1) - x;
      return (y * 16) + reversedX;
    } else {
      return (y * 16) + x;
    }
  }
};