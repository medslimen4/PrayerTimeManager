#ifndef DIGITAL_HPP
#define DIGITAL_HPP

#include "..\lib\Domaine\Services\IDigital\Idigital.hpp"
#include <Arduino.h>

class Digital : public IDigital
{
public:
  unsigned char read(unsigned char address) override;
  void write(unsigned char address, unsigned char value) override;
};
#endif // DIGITAL_HPP
