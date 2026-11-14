#pragma once

#include <MqttClientService.h>

/**
 * @file MqttOtaRequestReader.h
 * @brief Defines an MQTT reader for OTA update requests.
 */

/**
 * @brief Receives and processes OTA update requests via MQTT.
 *
 * Uses MqttClientService to subscribe to an OTA request topic
 * and process incoming MQTT messages.
 *
 * Maintains an internal flag indicating whether an OTA update
 * has been requested.
 *
 * The MQTT client service is referenced but not owned by this class.
 */
class MqttOtaRequestReader
{
    private:
        MqttClientService& mqttClientService;
        bool otaRequested = false;

    public:

        /**
         * @brief Constructs an MQTT OTA request reader.
         *
         * @param mqttClientService Reference to the MQTT client service.
         *                          The service must outlive this instance.
         */
        explicit MqttOtaRequestReader(MqttClientService& mqttClientService) : mqttClientService(mqttClientService) {}
        
        /**
         * @brief Subscribes to the configured OTA request topic.
         *
         * @return True if the subscription succeeds, false otherwise.
         */
        bool subscribe();

        /**
         * @brief Returns the current OTA request state.
         *
         * The state is initially false and is updated when a valid
         * OTA request message is processed.
         *
         * @return True if an OTA update is requested, false otherwise.
         */
        bool isOtaRequested() const;

        /**
         * @brief Processes an incoming MQTT OTA request message.
         *
         * Validates the MQTT topic and interprets the payload.
         *
         * A payload of "true" sets the OTA request flag, while "false"
         * clears it. Invalid topics or payloads are rejected without
         * changing the current request state.
         *
         * @param topic Received MQTT topic.
         * @param payload Received MQTT message payload.
         * @return True if a valid OTA request message was processed,
         *         false otherwise.
         */
        bool processMessage(const char* topic, const char* payload);
};