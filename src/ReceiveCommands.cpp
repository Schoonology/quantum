/**
 * Quantum library by Michael Schoonmaker
 */

#include "ReceiveCommands.h"

ReceiveCommands::ReceiveCommands(int port, void perform (uint8_t), int interval)
  : perform(perform)
  , server(port)
  , timer(interval, &ReceiveCommands::receive, *this) {
}

ReceiveCommands::~ReceiveCommands() {}

void ReceiveCommands::begin() {
  server.begin();
  timer.start();
}

void ReceiveCommands::receive() {
  forwardAvailableBytes();

  if (!client.connected()) {
    client = server.available();
  }
}

void ReceiveCommands::forwardAvailableBytes() {
  int byte = client.read();

  if (byte == -1) {
    return;
  }

  perform(byte & 0xff);
  forwardAvailableBytes();
}
