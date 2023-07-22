#include <iostream>
#include <string>

using namespace std;

class Configuration {
  public:
    string wol_svr_ip_addr;

    Configuration(string &wol_svr_ip_addr);

    bool is_valid_ip_address(string &ip_addr);
};
