#ifndef LOCATION_H
#define LOCATION_H

#define COORD_MAX 15
#define COORD_MIN 0
#define CORNER_UL 0
#define CORNER_UR 1
#define CORNER_BL 2
#define CORNER_BR 3
#define EDGE_U 4
#define EDGE_B 5
#define EDGE_L 6
#define EDGE_R 7

#include <Arduino.h>

class Location {
  private:
    uint8_t x;
    uint8_t y;

  public:

    Location() : Location(random() % 16, random() % 16) { }

    Location(uint8_t x, uint8_t y) : x(x), y(y) { }

    ~Location() { }


    void pick_edge(int which) {

      int rand = random(4, 8);
      int up_down = random(0, 2);

      switch (rand)
      {
      case EDGE_U:
        if (up_down) pick_corner(CORNER_UL);
        else pick_corner(CORNER_UR);
        break;

      case EDGE_B:
        if (up_down) pick_corner(CORNER_BL);
        else pick_corner(CORNER_BR);
        break;

      case EDGE_L:
        if (up_down) pick_corner(CORNER_UL);
        else pick_corner(CORNER_BL);
        break;
      
      default:
        if (up_down) pick_corner(CORNER_UR);
        else pick_corner(CORNER_BR);
        break;
      }
      
    }

    void pick_corner(int which) {
      int rand = random(0, 3);
        switch (which) {
        case CORNER_UL:
          if (rand == 0) this->x++;
          else if (rand == 1) this->y++;
          else {
            this->x++;
            this->y++;
          }
          break;

        case CORNER_UR:
          if (rand == 0) this->x--; 
          else if (rand == 1) this->y++;
          else {
            this->x--;
            this->y++;
          }
          break;

        case CORNER_BL:
          if (rand == 0) this->x++;
          else if (rand == 1) this->y--;
          else {
            this->x++;
            this->y--;
          }
          break;
        
        default:
          if (rand == 0) this->x--;
          else if (rand == 1) this->y--;
          else {
            this->x--;
            this->y--;
          } 
          break;
        }

    }

    void get_next_location() {
      if ((this->x == COORD_MAX) && (this->y == COORD_MAX)) pick_corner(CORNER_BR);
      else if ((this->x == COORD_MIN) && (this->y == COORD_MIN)) pick_corner(CORNER_UL);

      else if ((this->x == COORD_MIN) && (this->y == COORD_MAX)) pick_corner(CORNER_BL);
      else if ((this->x == COORD_MAX) && (this->y == COORD_MIN)) pick_corner(CORNER_UR);
      else if (this->x == COORD_MIN) pick_edge(EDGE_L);
      else if (this->x == COORD_MAX) pick_edge(EDGE_R);
      else if (this->y == COORD_MIN) pick_edge(EDGE_U);
      else if (this->y == COORD_MAX) pick_edge(EDGE_B);
      else {
          switch (random(0, 9)) {
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
