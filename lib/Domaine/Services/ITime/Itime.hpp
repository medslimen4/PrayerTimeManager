#ifndef ITIME_HPP
#define ITIME_HPP
#include <iostream>
#include "ctime"

#include "..\lib\Domaine\ValueObject\CustomTime\CustomTime.hpp"
class ITime
{
public:
    virtual bool SetTimeToRtc() = 0;
    virtual int LoadTimeFromRtcAsMin() = 0;
    virtual CustomTime getCurrentTime() = 0;
};

#endif // ITIME_HPP
