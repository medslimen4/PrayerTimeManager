#include "RTC.hpp"

bool RTC::SetTimeToRtc()
{

    if (!rtc.begin())
    {
        Serial.println("Couldn't find RTC");
        while (1)
            ;
    }

    if (!rtc.isrunning())
    {
        Serial.println("RTC is NOT running!");
    }
    if (WiFi.status() == WL_CONNECTED)
    {
        NTPClient timeClient(ntpUDP, "pool.ntp.org", 3600 * 1, 60000); // CET (UTC+1)
        timeClient.begin();
        while (!timeClient.update())
        {
            timeClient.forceUpdate();
        }
        rtc.adjust(DateTime(timeClient.getEpochTime()));
        return 1;
    }
    else
    {
        return 0;
    }
};

int RTC::LoadTimeFromRtcAsMin()
{
    if (!rtc.begin())
    {
        Serial.println("Couldn't find RTC");
        while (1)
            ;
    }

    if (!rtc.isrunning())
    {
        Serial.println("RTC is NOT running!");
    }
    DateTime now = rtc.now();
    int currentMinutes = now.hour() * 60 + now.minute();
    return currentMinutes;
}

CustomTime RTC::getCurrentTime()
{
    if (!rtc.begin())
    {
        Serial.println("Couldn't find RTC");
        while (1)
            ;
    }

    if (!rtc.isrunning())
    {
        Serial.println("RTC is NOT running!");
    }
    DateTime dt = rtc.now();
    CustomTime customTime = {dt.hour(), dt.minute(), dt.second()};
    // test
    Serial.print(dt.hour(), DEC);
    Serial.print(':');
    Serial.print(dt.minute(), DEC);
    Serial.print(':');
    Serial.println(dt.second(), DEC);
    return customTime;
}
