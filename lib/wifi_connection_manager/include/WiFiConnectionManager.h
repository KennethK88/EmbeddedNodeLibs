#pragma once

/**
 * @file WiFiConnectionManager.h
 * @brief Defines a service for managing ESP32 Wi-Fi connections.
 */

/**
 * @brief Manages Wi-Fi initialization and connectivity.
 *
 * Encapsulates the ESP32 Wi-Fi connection setup and provides
 * functionality for establishing and monitoring a Wi-Fi connection.
 *
 * The service can be used independently of application-specific
 * communication protocols.
 */
class WiFiConnectionManager
{
    public:

        /**
         * @brief Constructs a Wi-Fi connection manager.
         */
        WiFiConnectionManager() = default;

        /**
         * @brief Initializes the Wi-Fi component.
         *
         * Configures the ESP32 Wi-Fi stack for station mode.
         */
        void init();

        /**
         * @brief Attempts to establish a Wi-Fi connection.
         *
         * Initiates a connection using the configured credentials
         * and checks the connection status at 500 ms intervals.
         *
         * Returns when connected or after a timeout of 10 seconds.
         * Does nothing if already connected.
         *
         * The connection state can be checked using isConnected().
         */
        void connect();

        /**
         * @brief Checks whether the Wi-Fi connection is established.
         *
         * @return True if connected to Wi-Fi, false otherwise.
         */
        bool isConnected();
};