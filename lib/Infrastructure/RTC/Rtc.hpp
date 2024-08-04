#ifndef RTC_HPP
#define RTC_HPP
#include "..\Domaine\Services\ITime\Itime.hpp"
#include "RTClib.h"
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

class RTC : public ITime
{
private:
    RTC_DS1307 rtc;
    WiFiUDP ntpUDP;

public:
    bool SetTimeToRtc() override;
    int LoadTimeFromRtcAsMin() override;
    CustomTime getCurrentTime() override;
};
#endif // RTC_HPP
