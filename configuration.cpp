#include "configuration.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

Configuration::Configuration() {
    wol_svr_ip_addr = "";
}

void Configuration::set_wol_svr_ip_addr(string &wol_svr_ip_addr) {
    if (is_valid_ip_addr(wol_svr_ip_addr)) {
        wol_svr_ip_addr = wol_svr_ip_addr;
    } else {
        throw invalid_argument("Invalid IPv4 address.\n");
    }
}

bool Configuration::is_valid_ip_addr(string &ip_addr) {
    std::stringstream ss(ip_addr);
    std::string segment;
    std::vector<std::string> segments;

    while (std::getline(ss, segment, '.')) {
        segments.push_back(segment);
    }

    if (segments.size() != 4) {
        return false;
    }

    for (std::string &seg : segments) {
        if (seg.empty() || seg.size() > 3 || (seg.size() > 1 && seg[0] == '0')) {
            return false;
        }

        for (char c : seg) {
            if (!isdigit(c)) {
                return false;
            }
        }

        int segInt = std::stoi(seg);
        if (segInt < 0 || segInt > 255) {
            return false;
        }
    }

    return true;
}
