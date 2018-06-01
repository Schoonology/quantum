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
  pullNextPage();

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
  size_t available = client.available();

  if (!available) {
    return;
  }

  size_t length = available > 32 ? 32 : available;
  uint8_t *buffer = new uint8_t[length];
  size_t bytesRead = client.read(buffer, length);

  forwardReceived(buffer, bytesRead);
}
