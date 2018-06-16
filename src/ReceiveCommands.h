/**
 * Quantum library by Michael Schoonmaker
 */

#include "Particle.h"

class ReceiveCommands {
public:
  ReceiveCommands(int port, void perform (uint8_t), int interval);
  ~ReceiveCommands();

  void begin();
  void receive();

private:
  void forwardAvailableBytes();

  TCPClient client;
  void (*perform) (uint8_t);
  TCPServer server;
  Timer timer;
};
