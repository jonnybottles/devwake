#include "menu.h"
#include <algorithm>
#include <cctype>
#include <csignal>
#include <cstdlib>
#include <fstream>
#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

Menu::Menu(const string &menu_name) : menu_name(menu_name) {
    print_menu_name(menu_name);
}

void Menu::clear_screen(void) {
#ifdef _WIN32
    system("cls"); // For Windows
#else
    cout << "\033[2J\033[1;1H"; // ANSI escape code to clear the screen
#endif
}

void Menu::print_menu_name(const string &menu_name) {

    cout << "***** " << menu_name << " *****\n";
}

string Menu::get_string(const string &prompt) {
    // Register signal handler for SIGINT
    signal(SIGINT, quit_program);

    string response;
    while (true) {
        cout << prompt;
        // Check to see if the input stream is still good.
        if (!getline(cin, response)) {
            // If its not good and we have reached eof (e.g. ctrl-d / ctrl-c)
            if (cin.eof()) {
                quit_program(EOF);
                // Otherwise if there are any other input stream errors, quit the program.
            } else {
                quit_program(1);
            }
        } else {
            break;
        }
    }
    return response;
}

void Menu::quit_program(int signal) {
    if (signal == SIGINT || signal == EOF) {
        cout << "\nExiting program.\n";
    } else {
        cerr << "Input error. Exiting program." << std::endl;
    }

    exit(signal);
}