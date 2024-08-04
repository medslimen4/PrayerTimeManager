#ifndef PRAYERTIMEALERT_HPP
#define PRAYERTIMEALERT_HPP

#include "..\lib\Domaine\Services\ITime\Itime.hpp"
#include "..\lib\Domaine\Services\IFile\Ifile.hpp"
#include "..\lib\Domaine\Entities\PrayerTime\prayerTime.hpp"

class PrayerTimeAlert
{
private:
    ITime *RTC;
    IFile *SPIFFSStorage;
    PrayerTimes PT;
    int timeToMinutes(String time);
    bool istime(String prayerTime);

public:
    PrayerTimeAlert(ITime *RTC, IFile *SPIFFSStorage) : RTC(RTC), SPIFFSStorage(SPIFFSStorage) {}
    bool isTimeForPrayer();
};

#endif // PRAYERTIMEALERT_HPP
