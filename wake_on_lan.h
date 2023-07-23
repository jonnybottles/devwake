#ifndef WAKE_ON_LAN_H
#define WAKE_ON_LAN_H

#include "configuration.h"
#include <libssh/libssh.h>

class SSHClient {
  private:
    ssh_session session;

  public:
    SSHClient(Configuration the_configuration);

    // The tilda is used to indicate a destructor in c++
    ~SSHClient();

    void connect();
    void authenticate();
    void disconnect();
};

#endif