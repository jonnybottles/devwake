#include "menu.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    Menu theMainMenu("DEV WAKE");
    string server_ip_address = theMainMenu.get_string("Please WakeOnLan server IP Address: ");

    cout << "WakeOnLan server IP: " << server_ip_address << "\n";

    return 0;
}