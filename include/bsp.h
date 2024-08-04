#include<Stream.h>
#define         relayControlPin       14               // relayControlPin pin
bool            isRelayOn=            false;
const long      relayOnDuration=      60000;
unsigned long   relayStartTime;
const char      *ssid=                "HUAWEI";        // WiFi credentials
const char      *password=            "nassim555";
const char      *serverUrl=           "http://ethical-deedee-masjid-4e9a147c.koyeb.app/api/v1/masjid-oqba-bn-nafii-lqadim-lqtar-2181-tunisia/prayer-times"; //  IP address of the server and the port where your API is running



