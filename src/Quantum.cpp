/* Quantum library by Michael Schoonmaker
 */

#include "Quantum.h"

/**
 * Constructor.
 */
Quantum::Quantum()
{
  // be sure not to call anything that requires hardware be initialized here, put those in begin()
}

/**
 * Example method.
 */
void Quantum::begin()
{
    // initialize hardware
    Serial.println("called begin");
}

/**
 * Example method.
 */
void Quantum::process()
{
    // do something useful
    Serial.println("called process");
    doit();
}

/**
* Example private method
*/
void Quantum::doit()
{
    Serial.println("called doit");
}
