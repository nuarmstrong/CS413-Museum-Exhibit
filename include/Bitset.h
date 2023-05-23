#ifndef BITSET_H
#define BITSET_H

#include <Arduino.h>

#define bitSet(value, idx) ((value) |= (1ULL << (idx)))
#define bitClear(value, idx) ((value) &= ~(1ULL << (idx)))
#define bitRead(value, idx) ((value) & (1ULL << (idx)))

class BitSet {
    private:
        uint64_t lowest, low, high, highest;

    public:
        BitSet() : lowest(0), low(0), high(0), highest(0) { }

        ~BitSet() { }

        void set(uint16_t index) {
            if (index < 64) {
                bitSet(this->lowest, index);
            } 
            else if (index < 128) {
                bitSet(this->low, index - 64);
            }
            else if (index < 192) {
                bitSet(this->high, index - 128);
            }
            else {
                bitSet(this->highest, index - 192);
            }
        }

        void clear(uint16_t index) {
            if (index < 64) {
                bitClear(this->lowest, index);
            } 
            else if (index < 128) {
                bitClear(this->low, index - 64);
            }
            else if (index < 192) {
                bitClear(this->high, index - 128);
            }
            else {
                bitClear(this->highest, index - 192);
            }
        }

        bool get(uint16_t index) {
            if (index < 64) {
                return bitRead(this->lowest, index);
            } 
            else if (index < 128) {
                return bitRead(this->low, index - 64);
            }
            else if (index < 192) {
                return bitRead(this->high, index - 128);
            }
            else {
                return bitRead(this->highest, index - 192);
            }
        }


};

#endif // BITSET_H