#pragma once

#include <MqttClientService.h>

/**
 * @file MqttOtaStatusPublisher.h
 * @brief Defines an MQTT publisher for OTA maintenance window status.
 */

/**
 * @brief Publishes OTA maintenance window status information via MQTT.
 *
 * Uses MqttClientService to notify an MQTT broker when the
 * OTA maintenance window is opened or closed.
 *
 * The MQTT client service is referenced but not owned by this class.
 */
class MqttOtaStatusPublisher
{
    private:
        MqttClientService& mqttClientService;

    public:

        /**
         * @brief Constructs an OTA status publisher.
         *
         * @param mqttClientService Reference to the MQTT client service.
         *                          The service must outlive this instance.
         */
        explicit MqttOtaStatusPublisher(MqttClientService& mqttClientService) : mqttClientService(mqttClientService) {}
        
        /**
         * @brief Publishes the open state of the OTA maintenance window.
         *
         * Publishes "window_open" to the configured OTA status topic
         * as a retained MQTT message with QoS 1.
         *
         * @return Result of the MQTT publishing operation.
         */
        bool publishWindowOpen();

        /**
         * @brief Publishes the closed state of the OTA maintenance window.
         *
         * Publishes "window_closed" to the configured OTA status topic
         * as a retained MQTT message with QoS 1.
         *
         * @return Result of the MQTT publishing operation.
         */
        bool publishWindowClosed();
};