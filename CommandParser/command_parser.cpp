#include "command_parser.h"
#include "../BitwiseOperations/bitwise_operations.h"
#include "../core/utils.h"

#include <iostream>
#include <sstream>

using namespace std;

void process_command(const string& userInput) {
    istringstream input_stream(userInput);

    string command;
    input_stream >> command;

    if (command == "help") {
        print_help();
        return;
    } else if (command == "exit") {
        exit(0);
    } else if (command == "bin") {
        unsigned int value;
        if (input_stream >> value) {
            cout << toBinaryString(value) << endl;
        } else {
            cout << "Error: bin requires one integer. Example: bin 10\n";
        }
        return;
    } else if (command == "set") {
        unsigned int value;
        int position;
        if (input_stream >> value >> position) {
            unsigned int result = set_bit(value, position);
            cout << "Decimal: " << result << endl;
            cout << "Binary : " << toBinaryString(result) << endl;
        } else {
            cout << "Error: set requires two integers. Example: set 4 1\n";
        }
        return;
    } else if (command == "clear") {
        unsigned int value;
        int position;
        if (input_stream >> value >> position) {
            unsigned int result = clear_bit(value, position);
            cout << "Decimal: " << result << endl;
            cout << "Binary : " << toBinaryString(result) << endl;
        } else {
            cout << "Error: clear requires two integers. Example: clear 5 0\n";
        }
        return;
    } else if (command == "toggle") {
        unsigned int value;
        int position;
        if (input_stream >> value >> position) {
            unsigned int result = toggle_bit(value, position);
            cout << "Decimal: " << result << endl;
            cout << "Binary : " << toBinaryString(result) << endl;
        } else {
            cout << "Error: toggle requires two integers. Example: toggle 9 3\n";
        }
        return;
    } else if (command == "check") {
        unsigned int value;
        int position;
        if (input_stream >> value >> position) {
            cout << (is_bit_set(value, position) ? "Set" : "Not Set") << endl;
        } else {
            cout << "Error: check requires two integers. Example: check 5 2\n";
        }
        return;
    }

    // Reset and prepare to parse expression-style input
    input_stream.clear();
    input_stream.str(userInput);

    char firstChar;
    input_stream >> firstChar;

    if (firstChar == '~') {
        unsigned int value;
        if (input_stream >> value) {
            unsigned int result = ~value & 0xFF; // limit to 8-bit
            cout << "Decimal: " << result << endl;
            cout << "Binary : " << toBinaryString(result) << endl;
        } else {
            cout << "Error: '~' requires one integer. Example: ~5\n";
        }
        return;
    } else {
        input_stream.putback(firstChar);
    }

    unsigned int a;
    char op;

    if (input_stream >> a >> op) {
        unsigned int b;
        if (op == '<' || op == '>') {
            char op2;
            if (input_stream >> op2 && op2 == op) {
                if (input_stream >> b) {
                    unsigned int result = (op == '<') ? (a << b) & 0xFF : (a >> b) & 0xFF;
                    cout << "Decimal: " << result << endl;
                    cout << "Binary : " << toBinaryString(result) << endl;
                } else {
                    cout << "Error: shift operation requires two integers. Example: 8 << 2\n";
                }
            } else {
                cout << "Error: expected '<<' or '>>'. Example: 4 << 1\n";
            }
        } else if (op == '&' || op == '|' || op == '^') {
            if (input_stream >> b) {
                unsigned int result = 0;
                if (op == '&') result = a & b;
                else if (op == '|') result = a | b;
                else if (op == '^') result = a ^ b;
                result = result & 0xFF;

                cout << "Decimal: " << result << endl;
                cout << "Binary : " << toBinaryString(result) << endl;
            } else {
                cout << "Error: bitwise operator requires two integers. Example: 5 & 3\n";
            }
        } else {
            cout << "Error: unrecognized operator '" << op << "'. Supported: &, |, ^, <<, >>, ~\n";
        }
    } else {
        cout << "Invalid input. Type 'help' to see valid commands and syntax.\n";
    }
}
