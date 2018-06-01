/**
 * Quantum library by Michael Schoonmaker
 */

#include "Quantum.h"

Quantum::Quantum(void perform (uint8_t)) {
  beacon = new SendBeacon(7777);
  receiver = new ReceiveCommands(7778, perform);
}

Quantum::~Quantum() {
  delete beacon;
  delete receiver;
}

void Quantum::begin() {
  beacon->begin();
  receiver->begin();
}
