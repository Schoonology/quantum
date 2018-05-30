#include "Quantum.h"

Quantum quantum(perform);

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
