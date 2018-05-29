#pragma once

/* Quantum library by Michael Schoonmaker
 */

// This will load the definition for common Particle variable types
#include "Particle.h"

// This is your main class that users will import into their application
class Quantum
{
public:
  /**
   * Constructor
   */
  Quantum();

  /**
   * Example method
   */
  void begin();

  /**
   * Example method
   */
  void process();

private:
  /**
   * Example private method
   */
  void doit();
};
