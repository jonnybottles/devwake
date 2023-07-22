#ifndef MENU_H
#define GROCERY_ORGANIZER_H

#include <string>

using namespace std;

class Menu {
  public:
    Menu(const string &menu_name);

    void print_menu_name(const string &menu_name);
    void clear_screen(void);
    string get_string(const string &prompt);
    static void quit_program(int signal);

  private:
    string menu_name;
};

#endif