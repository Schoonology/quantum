#include "Quantum.h"

Quantum quantum(perform, {
  beaconInterval: 5000,
  commandInterval: 5000,
  beaconPort: 1234,
  commandPort: 1337
});

void setup() {
  quantum.begin();
}

void loop() {
}

void perform(uint8_t command) {
  switch (command) {
    // Handle received command.
  }
}
