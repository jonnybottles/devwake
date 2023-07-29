#ifndef WAKE_ON_LAN_H
#define WAKE_ON_LAN_H

#include "configuration.h"

#ifdef _WIN32
#include <libssh.h>
#include <windows.h> // Use the correct case here; it may be lower or mixed case
#else
#include <libssh/libssh.h>
#endif

class WakeOnLAN {
  private:
    ssh_session session;
    Configuration the_configuration; // Add the_configuration member variable

  public:
    WakeOnLAN(Configuration the_configuration); // Correct the constructor name

    // The tilde (~) is used to indicate a destructor in C++
    ~WakeOnLAN();

    void connect();
    void authenticate();
    void disconnect();
    void send_wol_cmd();
    void handle_output(ssh_channel channel);
};

#endif
