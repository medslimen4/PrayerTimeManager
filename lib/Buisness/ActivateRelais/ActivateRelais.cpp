#include "ActivateRelais.hpp"

void ActivateRelais::triggerRelay() {


  digital->write(relayControlPin, 1);
  //delay(3000);  // Relay on for 3 minutes
  digital->write(relayControlPin, 0);

}
