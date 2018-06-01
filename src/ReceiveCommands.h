/**
 * Quantum library by Michael Schoonmaker
 */

#include "Particle.h"

class ReceiveCommands {
public:
  ReceiveCommands(int port, void perform (uint8_t));
  ~ReceiveCommands();

  void begin();
  void receive();

private:
  void forwardReceived(uint8_t *data, size_t size);
  void pullNextPage();

  TCPClient client;
  void (*perform) (uint8_t);
  TCPServer *server;
  Timer *timer;
};
