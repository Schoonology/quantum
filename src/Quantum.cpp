/**
 * Quantum library by Michael Schoonmaker
 */

#include "Quantum.h"

Quantum::Quantum(void perform (uint8_t))
  : beacon(7777, 1000)
  , receiver(7778, perform, 100) {
}

Quantum::Quantum(void perform (uint8_t), QuantumOptions options)
  : beacon(options.beaconPort, options.beaconInterval)
  , receiver(options.commandPort, perform, options.commandInterval) {
}

Quantum::~Quantum() {}

void Quantum::begin() {
  beacon.begin();
  receiver.begin();
}
