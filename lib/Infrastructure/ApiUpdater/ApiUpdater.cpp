#include "..\lib\Infrastructure\ApiUpdater\ApiUpdater.hpp"

bool ApiUpdater::fetchData()
{
    if (WiFi.status() == WL_CONNECTED)
    {
        http.begin(client, serverUrl);
        http.addHeader("User-Agent", "ESP8266");
        http.setTimeout(5000); // Set timeout to 5 seconds

        int httpCode = http.GET();

        if (httpCode == HTTP_CODE_OK)
        {
            String payload = http.getString();
            parseData(payload);
            http.end();
            savePrayerTimes(); // Save fetched data to SPIFFS
            Serial.println("Data Fetched");
            return true;
        }
        else
        {
            http.end();
        }
    }
    return false;
}

void ApiUpdater::parseData(const String &payload)
{
    StaticJsonDocument<512> doc;
    DeserializationError error = deserializeJson(doc, payload);

    if (!error)
    {
        prayerTimes.fajr = doc["fajr"].as<String>();
        prayerTimes.dohr = doc["dohr"].as<String>();
        prayerTimes.asr = doc["asr"].as<String>();
        prayerTimes.maghrib = doc["maghreb"].as<String>();
        prayerTimes.icha = doc["icha"].as<String>();
    }
}

void ApiUpdater::savePrayerTimes()
{
    if (fileHandler)
    {
        fileHandler->savePrayerTimes(prayerTimes);
    }
}
