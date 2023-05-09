#ifndef LOCATION_H
#define LOCATION_H

#include <Arduino.h>

class Location
{
private:
  uint8_t x;
  uint8_t y;

public:
  static const int X = 0;
  static const int Y = 1;

  Location(uint8_t x, uint8_t y);
  ~Location();

  void inc(const int y);
  void dec(const int y);
  void get_next_location();
  uint16_t get_index();
};

#endif // LOCATION_H
