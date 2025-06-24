#include <iostream>
#include <string>
#include "CommandParser/command_parser.h"

using namespace std;

const string EXIT_COMMAND = "exit";

int main() {
    string userInput;

    cout << "==============================\n";
    cout << " Bitwise Command-Line Toolkit\n";
    cout << "==============================\n";
    cout << "Type in a command or type 'help' for a list of commands.\n";

    while (true) {
        cout << "\n> ";
        getline(cin, userInput);

        if (userInput == EXIT_COMMAND) {
            cout << "Exiting Bitwise Toolkit. Goodbye.\n";
            break;
        }

        if (!userInput.empty()) {
            process_command(userInput);
        }
    }

    return 0;
}
