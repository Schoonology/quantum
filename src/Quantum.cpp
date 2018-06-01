/**
 * Quantum library by Michael Schoonmaker
 */

#include "Quantum.h"

Quantum::Quantum(void perform (uint8_t)) {
  beacon = new SendBeacon(7777, 1000);
  receiver = new ReceiveCommands(7778, perform, 100);
}

Quantum::Quantum(void perform (uint8_t), QuantumOptions options) {
  beacon = new SendBeacon(options.beaconPort, options.beaconInterval);
  receiver = new ReceiveCommands(options.commandPort, perform, options.commandInterval);
}

Quantum::~Quantum() {
  delete beacon;
  delete receiver;
}

void Quantum::begin() {
  beacon->begin();
  receiver->begin();
}
