[![Library Builds](https://github.com/KennethK88/EmbeddedNodeLibs/actions/workflows/build.yml/badge.svg?branch=main)](https://github.com/KennethK88/EmbeddedNodeLibs/actions/workflows/build.yml)
[![Native Tests](https://github.com/KennethK88/EmbeddedNodeLibs/actions/workflows/test.yml/badge.svg?branch=main)](https://github.com/KennethK88/EmbeddedNodeLibs/actions/workflows/test.yml)
[![Build Documentation](https://github.com/KennethK88/EmbeddedNodeLibs/actions/workflows/docs.yml/badge.svg?branch=main)](https://github.com/KennethK88/EmbeddedNodeLibs/actions/workflows/docs.yml)

# EmbeddedNodeLibs


## Project Goal

The goal of this project is to develop a collection of reusable C++ library components for embedded applications, with a current focus on ESP32-based systems. The libraries provide common functionality for battery monitoring, Wi-Fi and MQTT communication, and OTA firmware updates.

The project focuses on modular software architecture, separation of responsibilities, reusability, and testability.


## Library Components

| Category | Library | Purpose |
|---|---|---|
| Battery | `BatterySensor` | Battery level estimation |
| Battery | `ESP32BatteryDriver` | ESP32 battery voltage measurement |
| Connectivity | `WiFiConnectionManager` | Wi-Fi connection management |
| Connectivity | `MqttClientService` | MQTT communication |
| Firmware & OTA | `FirmwareUpdateService` | OTA firmware update handling |
| Firmware & OTA | `MqttOtaRequestReader` | MQTT-based OTA request detection |
| Firmware & OTA | `MqttOtaStatusPublisher` | OTA maintenance window status publishing |
| Firmware & OTA | `MqttFirmwareVersionPublisher` | Firmware version publishing |

Shared battery types, constants, and the `IBatteryDriver` interface are provided through `battery_common`.


## Current Status

EmbeddedNodeLibs is actively used in ESP32-based projects, including RoomClimateNode. The library components are functional and continue to evolve. Native unit tests are available for BatterySensor. Further improvements, including the removal of application-specific dependencies and the extension of native test coverage, are tracked in [GitHub Issues](https://github.com/KennethK88/EmbeddedNodeLibs/issues).


## Technologies

- C++17
- PlatformIO
- ESP32 / ESP32-C3
- Wi-Fi / MQTT
- Unity Test Framework
- GitHub Actions
- Doxygen
- PlantUML


## Integration

EmbeddedNodeLibs is currently integrated into PlatformIO projects as a Git submodule. The libraries are made available through the consuming project's PlatformIO configuration. An example of this integration can be found in [RoomClimateNode](https://github.com/KennethK88/RoomClimateNode).


## Documentation

- Class Diagram: [Diagram](docs/ClassDiagram.svg) | [PlantUML Source](docs/ClassDiagram.puml)
- [Git Conventions](docs/GitConventions.md)