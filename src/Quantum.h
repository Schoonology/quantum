#pragma once

/**
 * Quantum library by Michael Schoonmaker
 */

#include "SendBeacon.h"
#include "ReceiveCommands.h"

class Quantum {
public:
  Quantum(void perform (uint8_t));
  ~Quantum();

  void begin();

private:
  ReceiveCommands *receiver;
  SendBeacon *beacon;
};
