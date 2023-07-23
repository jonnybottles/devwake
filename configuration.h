#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <iostream>
#include <string>

using namespace std;

class Configuration {
  public:
    string wol_svr_ip_addr;

    Configuration(void);

    void set_wol_svr_ip_addr(string &wol_svr_ip_addr);
    bool is_valid_ip_addr(string &ip_addr);
};

#endif