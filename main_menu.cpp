#include "main_menu.h"

#include <string>

using namespace std;

// Defines the constructor for hte main menu class and uses the constructor
// of the base class Menu to initilzie menu_name (Menu(menu_name))
MainMenu::MainMenu(const string &menu_name) : Menu(menu_name), the_configuration() {
    start();
}

void MainMenu::get_wol_svr_ip(void) {
    while (true) {
        try {
            the_configuration.wol_svr_ip_addr = get_string("Please enter WakeOnLan server IP Address: ");
            the_configuration.set_wol_svr_ip_addr(the_configuration.wol_svr_ip_addr);
            cout << "WakeOnLan server IP: " << the_configuration.wol_svr_ip_addr << "\n";
            break;
        }

        catch (invalid_argument &e) {
            cout << e.what() << "Please try again.\n";
        }
    }
}

void MainMenu::get_wol_tgt_ip(void) {
    while (true) {
        try {
            the_configuration.wol_tgt_ip_addr = get_string("Please enter IP address of the host you would like to wake up: ");
            the_configuration.set_wol_tgt_ip_addr(the_configuration.wol_tgt_ip_addr);
            cout << "WakeOnLan tgt IP: " << the_configuration.wol_tgt_ip_addr << "\n";
            break;
        }

        catch (invalid_argument &e) {
            cout << e.what() << "Please try again.\n";
        }
    }
}

void MainMenu::start() {
    get_wol_svr_ip();
    get_wol_tgt_ip();
}
