#include "main_menu.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    // Instantiate theMainMenu object with the title being "DEV WAKE"
    MainMenu theMainMenu("DEV WAKE");

    // //Obtain WakeOnLan server IP Address from user.
    // string wol_svr_ip_addr = theMainMenu.get_string("Please WakeOnLan server IP Address: ");

    // try {
    //     Configuration the_configuration(wol_svr_ip_addr);
    // } catch (invalid_argument& e) {

    // }

    // cout << "WakeOnLan server IP: " << wol_svr_ip_addr << "\n";

    return 0;
}