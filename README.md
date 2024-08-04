# ESP8266 Prayer Time Management System

This project is designed to manage and control prayer times using an ESP8266 microcontroller. The system fetches prayer times from an online API, stores them locally on the ESP8266 using SPIFFS, and triggers a relay to sound the Adhan at the appropriate times. The system is designed to work even when Wi-Fi is not available, using locally stored prayer times.

## Features

- **Fetch Prayer Times from API:** The system fetches prayer times from a specified API and stores them locally.
- **Local Storage:** Prayer times are stored in SPIFFS, allowing the system to function without an active internet connection.
- **RTC Synchronization:** The system sets and maintains the correct time using an RTC module.
- **Relay Control:** The system triggers a relay to sound the Adhan at the specified prayer times.
- **Wi-Fi Connectivity:** The system connects to a specified Wi-Fi network to fetch prayer times and synchronize the RTC.

## Architecture

This project is built using Clean Architecture principles and adheres to the SOLID principles of object-oriented design. The architecture ensures that the system is modular, maintainable, and scalable.

### Clean Architecture

- **Business Layer:** Contains the core business logic.
  - `ActivateRelais`: Controls the relay to sound the Adhan.
  - `PrayerTimeAlert`: Checks if it is time for prayer.
  - `PrayerTimeGlobalUpdate`: Updates prayer times from the API.

- **Domain Layer:** Represents the domain entities and services.
  - `Entities\PrayerTime`: Represents the prayer time entity.
  - `Services\IDigital`: Interface for digital operations.
  - `Services\IFile`: Interface for file operations.
  - `Services\ITime`: Interface for time operations.
  - `Services\IUpdateFromApi`: Interface for API update operations.
  - `ValueObject\CustomTime`: Represents custom time value objects.

- **Infrastructure Layer:** Handles external dependencies and implementations.
  - `ApiUpdater`: Handles fetching and parsing prayer times from the API.
  - `Digital`: Implements digital operations.
  - `RTC`: Implements time operations using the RTC module.
  - `SPIFFSStorage`: Implements file operations using SPIFFS.

### SOLID Principles

- **Single Responsibility Principle (SRP):** Each class has a single responsibility. For example, `ApiUpdater` is only responsible for fetching and parsing data from the API.
- **Open/Closed Principle (OCP):** Classes are open for extension but closed for modification. Interfaces like `IDigital`, `IFile`, `ITime`, and `IUpdateFromApi` allow for extending functionalities without modifying existing code.
- **Liskov Substitution Principle (LSP):** Subclasses or implementations can replace base classes or interfaces without affecting the functionality. Implementations like `Digital`, `SPIFFSStorage`, and `RTC` adhere to their respective interfaces.
- **Interface Segregation Principle (ISP):** Clients are not forced to depend on methods they do not use. Interfaces are specific to their functionalities.
- **Dependency Inversion Principle (DIP):** High-level modules depend on abstractions, not on concrete implementations. Dependencies are injected via constructors.

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
