#ifndef BITWISE_OPERATIONS_H
#define BITWISE_OPERATIONS_H

#include <string>
using namespace std;

// Convert integer to binary string
string toBinaryString(unsigned int value);

// Bit manipulation functions
unsigned int set_bit(unsigned int value, int position);
unsigned int clear_bit(unsigned int value, int position);
unsigned int toggle_bit(unsigned int value, int position);
bool is_bit_set(unsigned int value, int position);

#endif // BITWISE_OPERATIONS_H
