#include "PrayerTimeAlert.hpp"

bool PrayerTimeAlert::isTimeForPrayer()
{
    PT = SPIFFSStorage->loadPrayerTimes();
    if (istime(PT.fajr) || istime(PT.dohr) ||
        istime(PT.asr) || istime(PT.maghrib) ||
        istime(PT.icha))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int PrayerTimeAlert::timeToMinutes(String time)
{
    int hours = time.substring(0, 2).toInt();
    int minutes = time.substring(3, 5).toInt();
    return hours * 60 + minutes;
}

bool PrayerTimeAlert::istime(String prayerTime)
{

    int currentMinutes = RTC->LoadTimeFromRtcAsMin();
    int prayerMinutes = timeToMinutes(prayerTime);

    return currentMinutes == prayerMinutes;
}