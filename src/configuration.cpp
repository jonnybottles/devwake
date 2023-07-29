#include "configuration.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

Configuration::Configuration() {
    wol_svr_ip_addr = "";
    wol_tgt_ip_addr = "";
    wol_tgt_mac_addr = "";
}

void Configuration::set_wol_svr_ip_addr(string &new_wol_svr_ip_addr) {
    if (is_valid_ip_addr(new_wol_svr_ip_addr)) {
        this->wol_svr_ip_addr = new_wol_svr_ip_addr;
    } else {
        throw invalid_argument("Invalid IPv4 address.\n");
    }
}

void Configuration::set_wol_tgt_ip_addr(string &new_wol_tgt_ip_addr) {
    if (is_valid_ip_addr(new_wol_tgt_ip_addr)) {
        this->wol_tgt_ip_addr = new_wol_tgt_ip_addr;
    } else {
        throw invalid_argument("Invalid IPv4 address.\n");
    }
}

void Configuration::set_wol_tgt_mac_addr(string &new_wol_tgt_mac_addr) {
    if (is_valid_mac_addr(new_wol_tgt_mac_addr)) {
        this->wol_tgt_mac_addr = new_wol_tgt_mac_addr;
    } else {
        throw invalid_argument("Invalid MAC address.\n");
    }
}

bool Configuration::is_valid_mac_addr(const string &mac_addr) {
    std::stringstream ss(mac_addr);
    std::string segment;
    std::vector<std::string> segments;

    while (std::getline(ss, segment, ':')) {
        segments.push_back(segment);
    }

    if (segments.size() != 6) {
        return false;
    }

    for (std::string &seg : segments) {
        if (seg.size() != 2) {
            return false;
        }

        for (char c : seg) {
            if (!isxdigit(c)) {
                return false;
            }
        }
    }

    return true;
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

// Using const ensure that this function does not accidently change any member variables.
// Since this function only validates info, it should not be able to change info
bool Configuration::is_valid() const {
    // Check if the configuration is valid. This could be as simple as checking if
    // the IP addresses are not empty, or more complex depending on your needs.
    return !wol_svr_ip_addr.empty() && !wol_tgt_ip_addr.empty();
}
