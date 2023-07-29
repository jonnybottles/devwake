#include "configuration.h"
#include "main_menu.h"
#include "wake_on_lan.h"
#include <iostream>
#include <string>

using namespace std;

void usage(void) {
    cout << "***** DEVWAKE USAGE *****\n\n";
    cout << "Configure devwake via command line arguments.\n";
    cout << "./devwake -w [wake_on_lan_svr_ip_address] -t [target_wake_up_ip_address]\n\n";
    cout << "Configure devwake via the terminal user interface.\n";
    cout << "./devwake\n";
}

// Parses command line arguments in a manner that is OS agnostic, allowing it to work on NIX and Windows.
Configuration parse_arg_configs(int argc, char *argv[]) {
    Configuration the_configuration;
    // Iterate over the command-line arguments, skipping argv[0] (the program name)
    for (int i = 1; i < argc; ++i) {
        // Get the current argument as a string
        string arg = argv[i];

        // If the argument is "-w" (the WOL server IP option)...
        if (arg == "-w") {
            // If there is another argument after this one...
            if (i + 1 < argc) {
                // Create std::string from the next argument
                string next_arg = argv[++i];
                // Assign the next argument to the WOL IP variable and increment the index
                try {
                    the_configuration.set_wol_svr_ip_addr(next_arg);
                } catch (invalid_argument &e) {
                    cerr << e.what();
                    return Configuration(); // Empty configuration.
                }
            } else {
                // If there is no argument after "-w", output an error message and exit the program
                return Configuration(); // Empty configuration.
            }
        }
        // Else if the argument is "-t" (the target IP option)...
        else if (arg == "-t") {
            // If there is another argument after this one...
            if (i + 1 < argc) {
                // Create std::string from the next argument
                string next_arg = argv[++i];
                // Assign the next argument to the target IP variable and increment the index
                try {
                    the_configuration.set_wol_tgt_ip_addr(next_arg);
                } catch (invalid_argument &e) {
                    cerr << e.what();
                    return Configuration(); // Empty configuration.
                }
            } else {
                // If there is no argument after "-t", output an error message and exit the program
                return Configuration(); // Empty configuration.
            }
        }
        // Else if the argument is "-m" (the target MAC address option)...
        else if (arg == "-m") {
            // If there is another argument after this one...
            if (i + 1 < argc) {
                // Create std::string from the next argument
                string next_arg = argv[++i];
                // Assign the next argument to the target MAC address variable and increment the index
                try {
                    the_configuration.set_wol_tgt_mac_addr(next_arg);
                } catch (invalid_argument &e) {
                    cerr << e.what();
                    return Configuration(); // Empty configuration.
                }
            } else {
                // If there is no argument after "-m", output an error message and exit the program
                return Configuration(); // Empty configuration.
            }
        }
        // If the argument is unknown...
        else {
            // Output an error message and exit the program
            cerr << "Unknown argument: " << arg << "\n";
            return Configuration(); // Empty configuration
        }
    }

    // Return the constructed configuration
    return the_configuration;
}

int main(int argc, char *argv[]) {

    Configuration the_configuration;

    if (argc == 1) {
        MainMenu the_main_menu("DEV WAKE");
        the_configuration = the_main_menu.the_configuration;
    } else if (argc == 7) { // Updated for the additional "-m" option.
        the_configuration = parse_arg_configs(argc, argv);
        if (!the_configuration.is_valid()) {
            usage();
            return 1;
        }
    } else {
        usage();
        return 1;
    }

    WakeOnLAN the_wake_on_lan(the_configuration);
    try {
        the_wake_on_lan.connect();
        cout << "Connecting to WOL SVR...\n";
        cout << "Connected to WOL SVR: " << the_configuration.wol_svr_ip_addr << "\n";

        the_wake_on_lan.authenticate();
        cout << "Authenticating with WOL SVR...\n";
        cout << "Successfully authenticated to WOL SVR: " << the_configuration.wol_svr_ip_addr << "\n";

        the_wake_on_lan.send_wol_cmd();
        cout << "WOL SVR is sending WOL command to target host: " << the_configuration.wol_tgt_ip_addr << " / " << the_configuration.wol_tgt_mac_addr << "\n";

    } catch (runtime_error &e) {
        cerr << e.what();
    }

    // cout << "WakeOnLan server IP: " << the_configuration.wol_svr_ip_addr << "\n";
    // cout << "Target server IP: " << the_configuration.wol_tgt_ip_addr << "\n";
    // cout << "Target MAC address: " << the_configuration.wol_tgt_mac_addr << "\n";

    return 0;
}