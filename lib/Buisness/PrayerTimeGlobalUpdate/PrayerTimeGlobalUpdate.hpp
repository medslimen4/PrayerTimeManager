#ifndef PRAYERTIMEGLOBALUPDATE_HPP
#define PRAYERTIMEGLOBALUPDATE_HPP

#include "..\lib\Domaine\Services\IUpdateFromApi\IUpdateFromApi.hpp"
#include "..\lib\Domaine\Services\ITime\Itime.hpp"
#include "..\lib\Domaine\Services\IFile\Ifile.hpp"
#include "..\lib\Domaine\ValueObject\CustomTime\CustomTime.hpp"
class PrayerTimeGlobalUpdate
{
private:
    ITime *RTC;
    IUpdateFromApi *ApiUpdater;

public:
    PrayerTimeGlobalUpdate(ITime *RTC, IUpdateFromApi *ApiUpdater) : RTC(RTC), ApiUpdater(ApiUpdater) {}
    void updatePrayerTimes();
    void FirstUpdate();

};

#endif // PRAYERTIMEGLOBALUPDATE_HPP
