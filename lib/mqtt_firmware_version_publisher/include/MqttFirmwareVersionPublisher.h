#pragma once

#include <MqttClientService.h>

/**
 * @file MqttFirmwareVersionPublisher.h
 * @brief Defines an MQTT publisher for firmware version information.
 */

/**
 * @brief Publishes the current firmware version via MQTT.
 *
 * Uses MqttClientService to publish firmware version information
 * to an MQTT broker.
 *
 * The MQTT client service is referenced but not owned by this class.
 */
class MqttFirmwareVersionPublisher
{
    private:
        MqttClientService& mqttClientService;

    public:

        /**
         * @brief Constructs a firmware version publisher.
         *
         * @param mqttClientService Reference to the MQTT client service.
         *                          The service must outlive this instance.
         */
        explicit MqttFirmwareVersionPublisher(MqttClientService& mqttClientService) : mqttClientService(mqttClientService) {}

        /**
         * @brief Publishes the current firmware version via MQTT.
         *
         * Publishes the firmware version to the configured MQTT topic
         * as a retained message with QoS 1.
         *
         * @return Result of the MQTT publishing operation.
         */
        bool publishFirmwareVersion();
};