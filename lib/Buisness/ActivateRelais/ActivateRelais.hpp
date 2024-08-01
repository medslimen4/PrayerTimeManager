#ifndef ACTIVATERELAIS_HPP
#define ACTIVATERELAIS_HPP
#include"..\lib\Domaine\Services\IDigital\Idigital.hpp"
#include"..\include\bsp.h"

class ActivateRelais{
private:
    IDigital* digital;
public:
    ActivateRelais(IDigital* digital) : digital(digital) {}
    void triggerRelay();
};

#endif // ACTIVATERELAIS_HPP
