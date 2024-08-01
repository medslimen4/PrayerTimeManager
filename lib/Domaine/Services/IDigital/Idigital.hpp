#ifndef IDIGITAL_HPP
#define IDIGITAL_HPP

class IDigital {
public:
    virtual void write(unsigned char pin, unsigned char value) = 0;
    virtual unsigned char  read(unsigned char pin) = 0;

};

#endif // IDIGITAL_HPP
