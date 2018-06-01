/**
 * Quantum library by Michael Schoonmaker
 */

#include "ReceiveCommands.h"

ReceiveCommands::ReceiveCommands(int port, void perform (uint8_t))
  : perform(perform)
  , server(port)
  , timer(1000, &ReceiveCommands::receive, *this) {
}

ReceiveCommands::~ReceiveCommands() {}

void ReceiveCommands::begin() {
  server.begin();
  timer.start();
}

void ReceiveCommands::receive() {
  while (client.available()) {
    pullNextPage();
  }

  if (!client.connected()) {
    client = server.available();
  }
}

void ReceiveCommands::forwardReceived(uint8_t *data, size_t size) {
  for (size_t idx = 0; idx < size; ++idx) {
    perform(data[idx]);
  }
}

void ReceiveCommands::pullNextPage() {
  uint8_t buffer[32];
  memset(buffer, 0, 32);
  size_t bytesRead = client.read(buffer, 32);

  forwardReceived(buffer, bytesRead);
}
