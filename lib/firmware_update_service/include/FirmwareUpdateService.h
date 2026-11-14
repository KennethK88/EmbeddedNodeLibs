#pragma once

/**
 * @file FirmwareUpdateService.h
 * @brief Defines the service for over-the-air firmware updates.
 */

/**
 * @brief Manages OTA firmware updates on the ESP32.
 *
 * Initializes the ArduinoOTA service and provides functionality
 * for processing firmware uploads during a temporary maintenance window.
 */
class FirmwareUpdateService
{
    public:

        /**
         * @brief Initializes the ArduinoOTA service.
         *
         * Configures the Wi-Fi transmission power, OTA hostname,
         * and OTA password before starting the ArduinoOTA service.
         *
         * @return True if Wi-Fi transmission power configuration succeeds,
         *         false otherwise.
         */
        bool init();

        /**
         * @brief Processes pending OTA operations.
         *
         * Calls ArduinoOTA.handle() to process incoming OTA requests
         * and firmware upload operations.
         */
        void handle();

        /**
         * @brief Runs the OTA maintenance window for five minutes.
         *
         * Periodically processes OTA operations at approximately
         * 20 ms intervals until the maintenance window expires.
         *
         * A successful firmware update may trigger a device restart
         * before the method returns.
         *
         * @return True when the maintenance window completes normally.
         *         Does not indicate firmware update success.
         */        
        bool runMaintenanceWindow();
};