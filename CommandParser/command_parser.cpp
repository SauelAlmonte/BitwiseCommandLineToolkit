#include "command_parser.h"
#include "../BitwiseOperations/bitwise_operations.h"
#include "../core/utils.h"

#include <iostream>
#include <sstream>

using namespace std;

void process_command(const string& userInput) {
    istringstream input_stream(userInput);

    // For keyword-style commands like bin, set, clear, etc.
    string command;
    input_stream >> command;

    if (command == "help") {
        print_help();
        return;
    } else if (command == "exit") {
        exit(0);
    } else if (command == "bin") {
        int value;
        if (input_stream >> value) {
            cout << toBinaryString(value) << endl;
        } else {
            cout << "Error: bin requires one integer. Example: bin 10\n";
        }
        return;
    } else if (command == "set") {
        int value, position;
        if (input_stream >> value >> position) {
            cout << set_bit(value, position) << endl;
        } else {
            cout << "Error: set requires two integers. Example: set 4 1\n";
        }
        return;
    } else if (command == "clear") {
        int value, position;
        if (input_stream >> value >> position) {
            cout << clear_bit(value, position) << endl;
        } else {
            cout << "Error: clear requires two integers. Example: clear 5 0\n";
        }
        return;
    } else if (command == "toggle") {
        int value, position;
        if (input_stream >> value >> position) {
            cout << toggle_bit(value, position) << endl;
        } else {
            cout << "Error: toggle requires two integers. Example: toggle 9 3\n";
        }
        return;
    } else if (command == "check") {
        int value, position;
        if (input_stream >> value >> position) {
            if (is_bit_set(value, position)) {
                cout << "Set" << endl;
            } else {
                cout << "Not Set" << endl;
            }
        } else {
            cout << "Error: check requires two integers. Example: check 5 2\n";
        }
        return;
    }

    // Rewind stream to parse expressions like 5 & 7, ~9, 8 << 2
    input_stream.clear();
    input_stream.str(userInput);

    // Handle unary NOT: ~a
    char ch;
    input_stream >> ch;
    if (ch == '~') {
        int value;
        if (input_stream >> value) {
            cout << (~value) << endl;
        } else {
            cout << "Error: '~' requires one integer. Example: ~5\n";
        }
        return;
    } else {
        // Put the character back since it wasn't '~'
        input_stream.putback(ch);
    }

    // Handle binary expressions: a & b, a | b, a ^ b, a << b, a >> b
    int a, b;
    char op;

    if (input_stream >> a >> op) {
        if (op == '<' || op == '>') {
            char next;
            if (input_stream >> next && next == op) {
                if (input_stream >> b) {
                    if (op == '<') {
                        cout << (a << b) << endl;
                    } else {
                        cout << (a >> b) << endl;
                    }
                } else {
                    cout << "Error: shift operation requires two integers. Example: 4 << 2\n";
                }
            } else {
                cout << "Error: expected '<<' or '>>'. Example: 8 << 2\n";
            }
        } else if (op == '&' || op == '|' || op == '^') {
            if (input_stream >> b) {
                if (op == '&') {
                    cout << (a & b) << endl;
                } else if (op == '|') {
                    cout << (a | b) << endl;
                } else if (op == '^') {
                    cout << (a ^ b) << endl;
                }
            } else {
                cout << "Error: bitwise operator requires two integers. Example: 5 & 7\n";
            }
        } else {
            cout << "Error: unrecognized operator '" << op << "'\n";
        }
    } else {
        cout << "Invalid input. Type 'help' to see valid commands and examples.\n";
    }
}
