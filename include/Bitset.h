#ifndef BITSET_H
#define BITSET_H

#include <Arduino.h>

#define bitSet(value, idx) ((value) |= (1ULL << (idx)))
#define bitClear(value, idx) ((value) &= ~(1ULL << (idx)))
#define bitRead(value, idx) ((value) & (1ULL << (idx)))

class BitSet {
    private:
        // 1024 bits
        uint64_t bits[16];

    public:
        BitSet() {
            for (int i = 0; i < 16; i++)
                bits[i] = 0;
        }

        ~BitSet() { }

        void set(uint16_t index) {
            bitSet(this->bits[index / 64], index % 64);
        }

        void clear(uint16_t index) {
            bitClear(this->bits[index / 64], index % 64);
        }

        bool get(uint16_t index) {
            return bitRead(this->bits[index / 64], index % 64);
        }
};

#endif // BITSET_H
