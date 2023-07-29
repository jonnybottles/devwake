#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "configuration.h"
#include "menu.h"
#include <string>

using namespace std;

class MainMenu : public Menu {
  public:
    MainMenu(const string &menu_name);
    void get_wol_svr_ip(void);
    void get_wol_tgt_ip(void);
    void get_wol_tgt_mac(void);
    void start() override;
    Configuration the_configuration;
};

#endif