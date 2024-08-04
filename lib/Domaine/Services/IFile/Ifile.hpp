#ifndef IFILE_HPP
#define IFILE_HPP
#include "..\lib\Domaine\Entities\PrayerTime\prayerTime.hpp"
class IFile
{
public:
    virtual void savePrayerTimes(const PrayerTimes &prayerTimes) = 0;
    virtual PrayerTimes loadPrayerTimes() = 0;
};

#endif // IFILE_HPP
