#ifndef APIUPDATER_HPP
#define APIUPDATER_HPP

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#include <FS.h>
#include "..\lib\Domaine\Services\IUpdateFromApi\IUpdateFromApi.hpp"
#include "..\lib\Domaine\Entities\PrayerTime\prayerTime.hpp"
#include "..\lib\Domaine\Services\IFile\Ifile.hpp"
class ApiUpdater : public IUpdateFromApi
{
public:
    ApiUpdater(IFile *file ,const char *serverUrl) : fileHandler(file) , serverUrl(serverUrl) {}
    bool fetchData() override;
    void parseData(const String &payload) override;

    PrayerTimes getPrayerTimes() const { return prayerTimes; }

private:
    WiFiClient client;
    HTTPClient http;
    PrayerTimes prayerTimes;
    IFile *fileHandler;
    const char *serverUrl;

    void savePrayerTimes();
};

#endif // APIUPDATER_HPP
