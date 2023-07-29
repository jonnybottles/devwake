#define NOMINMAX
#include "wake_on_lan.h"
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Constructor for the WakeOnLAN class
WakeOnLAN::WakeOnLAN(Configuration the_configuration) : the_configuration(the_configuration) {
    // Create a new SSH session
    session = ssh_new();
    if (session == NULL) {
        throw runtime_error("Failed to create SSH session");
    }

    // Set the SSH options for the host using the WakeOnLAN server IP address
    // The .c_str converts the string that is wol_svr_ip_addr to a const void*
    // as this is the data type that is required for ssh_options_set
    std::string hostname = "pi@" + the_configuration.wol_svr_ip_addr;
    ssh_options_set(session, SSH_OPTIONS_HOST, hostname.c_str());

    // int verbosity = SSH_LOG_PROTOCOL;
    // ssh_options_set(session, SSH_OPTIONS_LOG_VERBOSITY, &verbosity);
}

// Destructor for the WakeOnLAN class
WakeOnLAN::~WakeOnLAN() {
    // Free the SSH session if it exists
    if (session != NULL) {
        ssh_free(session);
    }
}

// Function to connect to the SSH server
void WakeOnLAN::connect() {
    int rc = ssh_connect(session);
    if (rc != SSH_OK) {
        throw runtime_error(ssh_get_error(session));
    }
}

// Function to authenticate the SSH session using public key authentication
void WakeOnLAN::authenticate() {
    int rc = ssh_userauth_publickey_auto(session, NULL, NULL);
    if (rc == SSH_AUTH_ERROR) {
        throw runtime_error(ssh_get_error(session));
    }
}

// Function to send the Wake-on-LAN command to the target MAC address
void WakeOnLAN::send_wol_cmd() {
    ssh_channel channel = ssh_channel_new(session);
    if (channel == NULL) {
        throw runtime_error("Failed to open channel\n");
    }

    int rc = ssh_channel_open_session(channel);
    if (rc != SSH_OK) {
        ssh_channel_free(channel);
        throw runtime_error(string("Failed to open SSH session: ") + ssh_get_error(session)); // Add error info
    }

    // Construct the wakeonlan command with the target MAC address
    std::string command = "wakeonlan " + the_configuration.wol_tgt_mac_addr;
    rc = ssh_channel_request_exec(channel, command.c_str());
    if (rc != SSH_OK) {
        ssh_channel_close(channel);
        ssh_channel_free(channel);
        throw runtime_error("Failed to execute command\n");
    }

    // handle command output and errors here if needed...

    // Send EOF to the channel and close it
    ssh_channel_send_eof(channel);
    ssh_channel_close(channel);
    ssh_channel_free(channel);
}

// Function to disconnect the SSH session
void WakeOnLAN::disconnect() {
    ssh_disconnect(session);
}