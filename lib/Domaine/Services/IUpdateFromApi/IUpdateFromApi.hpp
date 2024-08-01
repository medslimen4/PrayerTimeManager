#ifndef IUPDATEFROMAPI_HPP
#define IUPDATEFROMAPI_HPP

#include "..\lib\Domaine\Entities\PrayerTime\prayerTime.hpp"
#include<Stream.h>
class IUpdateFromApi {
public:
    virtual bool fetchData() = 0;  // Fetches data from the API
    virtual void parseData(const String& payload) = 0;  // Parses the API response
};

#endif // IUPDATEFROMAPI_HPP
