#include "SPIFFSStorage.hpp"
#include<Arduino.h>
#include <ArduinoJson.h>
#include <LittleFS.h>
void SPIFFSStorage::savePrayerTimes(const PrayerTimes& prayerTimes) {
    File file = SPIFFS.open("/prayer_times.json", "w");
    if (!file) {
        return;
    }

    StaticJsonDocument<512> doc;
    doc["fajr"] = prayerTimes.fajr;
    doc["dohr"] = prayerTimes.dohr;
    doc["asr"] = prayerTimes.asr;
    doc["maghrib"] = prayerTimes.maghrib;
    doc["icha"] = prayerTimes.icha;

    serializeJson(doc, file);
    file.close();
}

PrayerTimes SPIFFSStorage::loadPrayerTimes() {
    PrayerTimes prayerTimes;
    File file = SPIFFS.open("/prayer_times.json", "r");
    if (!file) {
        return prayerTimes;
    }

    StaticJsonDocument<512> doc;
    DeserializationError error = deserializeJson(doc, file);
    if (!error) {
        prayerTimes.fajr = doc["fajr"].as<String>();
        prayerTimes.dohr = doc["dohr"].as<String>();
        prayerTimes.asr = doc["asr"].as<String>();
        prayerTimes.maghrib = doc["maghreb"].as<String>();
        prayerTimes.icha = doc["icha"].as<String>();
    }

    file.close();
    return prayerTimes;
}
