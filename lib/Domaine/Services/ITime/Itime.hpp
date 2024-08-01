#ifndef ITIME_HPP
#define ITIME_HPP
#include <iostream>
#include "ctime"

class ITime {
public:
    virtual bool SetTimeToRtc() = 0;
    virtual int LoadTimeFromRtcAsMin() = 0;
};

#endif // ITIME_HPP
