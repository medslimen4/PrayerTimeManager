#include "Digital.hpp"

unsigned char Digital::read(unsigned char address)
{
  return ::digitalRead(address);
}

void Digital::write(unsigned char address, unsigned char value)
{
  return ::digitalWrite(address, value);
}