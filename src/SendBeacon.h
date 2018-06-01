/**
 * Quantum library by Michael Schoonmaker
 */

#include "Particle.h"

class SendBeacon {
public:
  SendBeacon(int port, int interval);
  ~SendBeacon();

  void begin();

private:
  void compileBeaconData();
  void send();

  IPAddress address;
  uint8_t *data;
  size_t length;
  int port;
  UDP socket;
  Timer timer;
};
