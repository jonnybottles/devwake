#include "wake_on_lan.h"
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

SSHClient::SSHClient(Configuration the_configuration) {
    session = ssh_new();
    if (session == NULL) {
        throw runtime_error("Failed to create SSH session");
    }

    // The .c_str converts the string that is wol_svr_ip_addr to a const void*
    // as this is the data type that is requred for ssh_options_set
    ssh_options_set(session, SSH_OPTIONS_HOST, the_configuration.wol_svr_ip_addr.c_str());
}

SSHClient::~SSHClient() {
    if (session != NULL) {
        ssh_free(session);
    }
}

void SSHClient::connect() {
    int rc = ssh_connect(session);
    if (rc != SSH_OK) {
        throw runtime_error(ssh_get_error(session));
    }
}

void SSHClient::authenticate() {
    int rc = ssh_userauth_publickey_auto(session, NULL, NULL);
    if (rc == SSH_AUTH_ERROR) {
        throw runtime_error(ssh_get_error(session));
    }
}

void SSHClient::disconnect() {
    ssh_disconnect(session);
}
