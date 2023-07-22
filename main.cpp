#include "menu.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    Menu theMainMenu("DEV WAKE");
    string wol_svr_ip_addr = theMainMenu.get_string("Please WakeOnLan server IP Address: ");

    cout << "WakeOnLan server IP: " << wol_svr_ip_addr << "\n";

    return 0;
}