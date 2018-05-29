// Example usage for Quantum library by Michael Schoonmaker.

#include "Quantum.h"

// Initialize objects from the lib
Quantum quantum;

void setup() {
    // Call functions on initialized library objects that require hardware
    quantum.begin();
}

void loop() {
    // Use the library's initialized objects and functions
    quantum.process();
}
