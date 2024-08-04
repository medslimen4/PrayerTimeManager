#include "PrayerTimeGlobalUpdate.hpp"

void PrayerTimeGlobalUpdate::updatePrayerTimes()
{

    CustomTime now = RTC->getCurrentTime();
    
    if (now.hour == 0 && now.minute == 0 && now.second == 0)
    {
        ApiUpdater->fetchData();
    }
}


void PrayerTimeGlobalUpdate::FirstUpdate()
{

        ApiUpdater->fetchData();
    
}