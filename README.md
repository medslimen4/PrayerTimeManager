# ESP8266 Prayer Time Management System

This project is designed to manage and control prayer times using an ESP8266 microcontroller. The system fetches prayer times from an online API, stores them locally on the ESP8266 using SPIFFS, and triggers a relay to sound the Adhan at the appropriate times. The system is designed to work even when Wi-Fi is not available, using locally stored prayer times.

## Features

- **Fetch Prayer Times from API:** The system fetches prayer times from a specified API and stores them locally.
- **Local Storage:** Prayer times are stored in SPIFFS, allowing the system to function without an active internet connection.
- **RTC Synchronization:** The system sets and maintains the correct time using an RTC module.
- **Relay Control:** The system triggers a relay to sound the Adhan at the specified prayer times.
- **Wi-Fi Connectivity:** The system connects to a specified Wi-Fi network to fetch prayer times and synchronize the RTC.

## Components

- **ESP8266:** The main microcontroller used for running the system.
- **Relay Module:** Used to control the sounding of the Adhan.
- **RTC Module (DS1307):** Used to keep track of the current time.
- **SPIFFS:** File system used for storing prayer times locally.
- **Wi-Fi:** Used to fetch prayer times from the online API.

## Directory Structure

```plaintext
.
├── include
│   └── bsp.h
├── lib
│   ├── Business
│   │   ├── ActivateRelais
│   │   ├── PrayerTimeAlert
│   │   └── PrayerTimeGlobalUpdate
│   ├── Domaine
│   │   ├── Entities
│   │   │   └── PrayerTime
│   │   ├── Services
│   │   │   ├── IDigital
│   │   │   ├── IFile
│   │   │   ├── ITime
│   │   │   └── IUpdateFromApi
│   │   └── ValueObject
│   │       └── CustomTime
│   └── Infrastructure
│       ├── ApiUpdater
│       ├── Digital
│       ├── esp8266
│       ├── RTC
│       └── SPIFFSStorage
├── src
│   └── main.cpp
└── README.md
