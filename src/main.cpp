#include <Arduino.h>
#include <TaskScheduler.h>

#include "..\lib\Buisness\PrayerTimeAlert\PrayerTimeAlert.hpp"
#include "..\lib\Buisness\ActivateRelais\ActivateRelais.hpp"
#include "..\lib\Buisness\PrayerTimeGlobalUpdate\PrayerTimeGlobalUpdate.hpp"
#include "..\lib\Infrastructure\ApiUpdater\ApiUpdater.hpp"
#include "..\lib\Infrastructure\RTC\Rtc.hpp"
#include "..\lib\Infrastructure\SPIFFSStorage\SPIFFSStorage.hpp"
#include "..\lib\Infrastructure\Digital\Digital.hpp"
#include "..\include\bsp.h"
// instance
Digital digital;
RTC rtc;
SPIFFSStorage spiffsStorage;

ApiUpdater apiUpdater(&spiffsStorage, serverUrl);
ActivateRelais activateRelais(&digital, relayControlPin);
PrayerTimeAlert prayerTimeAlert(&rtc, &spiffsStorage);
PrayerTimeGlobalUpdate prayerTimeGlobalUpdate(&rtc, &apiUpdater);

void setup()
{
  Serial.begin(115200);

  pinMode(relayControlPin, OUTPUT);
  activateRelais.RelayOff();

  // Initialize SPIFFS
  if (!SPIFFS.begin())
  {
    Serial.println("Failed to mount file system");
    return;
  }

  // Attempt to connect to Wi-Fi
  WiFi.begin(ssid, password);
  int wifiRetries = 0;
  while (WiFi.status() != WL_CONNECTED && wifiRetries < 20)
  {
    delay(3000);
    Serial.print(".");
    wifiRetries++;
  }

  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println("WiFi connected");
    if (!rtc.SetTimeToRtc())
    {
      Serial.println("Failed to set time on RTC via NTP");
    }
    prayerTimeGlobalUpdate.FirstUpdate();
    Serial.println("First Update Done");
  }
  else
  {
    Serial.println("WiFi not connected");
  }
}

void loop()
{
  // Check if it's time to update the prayer times
  if (WiFi.status() == WL_CONNECTED)
  {
    prayerTimeGlobalUpdate.updatePrayerTimes();
  }
  else
  {
    Serial.println("WiFi not connected, using stored prayer times");
  }

  // Check if it's time for prayer
  if (prayerTimeAlert.isTimeForPrayer() && !isRelayOn)
  {
    activateRelais.RelayOn();
    isRelayOn = true;
    relayStartTime = millis();
  }
  if (isRelayOn && (millis() - relayStartTime >= relayOnDuration))
  {
    activateRelais.RelayOff();

    isRelayOn = false;
  }

  delay(1000); // Delay for 1 second before the next loop iteration
}
