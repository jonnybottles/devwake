#ifndef MENU_H
#define MENU_H

#include <string>

using namespace std;

class Menu {
  public:
    Menu(const string &menu_name);

    void print_menu_name(const string &menu_name);
    void clear_screen(void);
    string get_string(const string &prompt);
    static void quit_program(int signal);

    // This is a pure virtual function. This is not implemented in the Menu class.
    // With pure virtual functions this forces all child classes of a class to
    // override the virtual function and provide it' own implementation.
    virtual void start() = 0;

  private:
    string menu_name;
};

#endif