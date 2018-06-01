#pragma once

/**
 * Quantum library by Michael Schoonmaker
 */

#include "SendBeacon.h"
#include "ReceiveCommands.h"

struct QuantumOptions {
  int beaconInterval;
  int commandInterval;
  int beaconPort;
  int commandPort;
};

class Quantum {
public:
  Quantum(void perform (uint8_t));
  Quantum(void perform (uint8_t), QuantumOptions options);
  ~Quantum();

  void begin();

private:
  SendBeacon beacon;
  ReceiveCommands receiver;
};
