#include "ActivateRelais.hpp"

void ActivateRelais::RelayOn()
{

  digital->write(relayControlPin, 0);
}
void ActivateRelais::RelayOff(){
  digital->write(relayControlPin, 1);
}
