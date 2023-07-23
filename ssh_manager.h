#ifndef _H
#define _H

#include <iostream>
#include <string>

using namespace std;

class Configuration {
  public:
    string wol_svr_ip_addr;
    string wol_tgt_ip_addr;

    Configuration(void);

    void set_wol_svr_ip_addr(string &wol_svr_ip_addr);
    void set_wol_tgt_ip_addr(string &wol_svr_ip_addr);
    bool is_valid_ip_addr(string &ip_addr);
    bool is_valid() const;
};

#endif