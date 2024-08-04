#ifndef ACTIVATERELAIS_HPP
#define ACTIVATERELAIS_HPP
#include "..\lib\Domaine\Services\IDigital\Idigital.hpp"
class ActivateRelais
{
private:
    IDigital *digital;
    int relayControlPin;

public:
    ActivateRelais(IDigital *digital , int relayControlPin) : digital(digital) , relayControlPin(relayControlPin){}
    void RelayOn();
    void RelayOff();
};

#endif // ACTIVATERELAIS_HPP
