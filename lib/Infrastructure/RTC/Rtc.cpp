#include "RTC.hpp"

bool RTC::SetTimeToRtc()
{
if (WiFi.status() == WL_CONNECTED)
{
NTPClient timeClient(ntpUDP, "pool.ntp.org", 3600 * 1, 60000); // CET (UTC+1)
rtc.adjust(DateTime(timeClient.getEpochTime()));
return 1;
}
else{
    return 0;
}
};


int RTC::LoadTimeFromRtcAsMin(){
      DateTime now = rtc.now();
      int currentMinutes = now.hour() * 60 + now.minute();
  return  currentMinutes;
}






