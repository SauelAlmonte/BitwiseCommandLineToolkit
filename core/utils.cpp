#include "utils.h"
#include <iostream>

using namespace std;

void print_help() {
    cout << "\nAvailable Commands (Expression Style):\n";
    cout << "  a & b         - Bitwise AND\n";
    cout << "  a | b         - Bitwise OR\n";
    cout << "  a ^ b         - Bitwise XOR\n";
    cout << "  ~a            - Bitwise NOT (Negate)\n";
    cout << "  a << n        - Left shift a by n positions\n";
    cout << "  a >> n        - Right shift a by n positions\n";

    cout << "\nKeyword-Based Commands:\n";
    cout << "  bin a         - Show binary (8-bit) representation with '0b' prefix\n";
    cout << "  set a pos     - Set bit at position 'pos'\n";
    cout << "  clear a pos   - Clear bit at position 'pos'\n";
    cout << "  toggle a pos  - Toggle bit at position 'pos'\n";
    cout << "  check a pos   - Check if bit at position 'pos' is set (0 or 1)\n";
    cout << "  help          - Show this help menu\n";
    cout << "  exit          - Exit the program\n";
}

