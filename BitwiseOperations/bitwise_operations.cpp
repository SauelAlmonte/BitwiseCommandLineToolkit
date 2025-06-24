#include "bitwise_operations.h"
#include <bitset>

using namespace std;

// Convert an unsigned integer to a 32-bit binary string
string toBinaryString(unsigned int value) {
    bitset<8> binary(value);
    return "0b" + binary.to_string();
}

// Set a bit at the given position (turns it to 1)
unsigned int set_bit(unsigned int value, int position) {
    return value | (1 << position);
}

// Clear a bit at the given position (turns it to 0)
unsigned int clear_bit(unsigned int value, int position) {
    return value & ~(1 << position);
}

// Toggle a bit at the given position (0 becomes 1, 1 becomes 0)
unsigned int toggle_bit(unsigned int value, int position) {
    return value ^ (1 << position);
}

// Check if a bit at the given position is set (i.e., equals 1)
bool is_bit_set(unsigned int value, int position) {
    return (value & (1 << position)) != 0;
}
