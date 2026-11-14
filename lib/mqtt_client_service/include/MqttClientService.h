#pragma once

#include <cstddef>
#include <WiFi.h>
#include <ArduinoMqttClient.h>

/**
 * @file MqttClientService.h
 * @brief Defines a service for MQTT communication over Wi-Fi.
 */

/**
 * @brief Manages MQTT connections and message communication.
 *
 * Encapsulates the Arduino MQTT client and provides functionality
 * for connecting to an MQTT broker, publishing messages,
 * subscribing to topics, and receiving messages.
 *
 * The service is independent of application-specific MQTT topics
 * and payload formats.
 *
 * The underlying network connection is provided by an ESP32 Wi-Fi client.
 */
class MqttClientService
{
    private:
        WiFiClient wifiClient;
        MqttClient mqttClient{wifiClient};

    public:

        /**
         * @brief Constructs an MQTT client service.
         */
        MqttClientService() = default;

        /**
         * @brief Initializes the MQTT client.
         *
         * Configures the MQTT client ID and authentication credentials.
         */
        void init();

        /**
         * @brief Attempts to connect to the MQTT broker.
         *
         * Retries the connection until it succeeds or the configured
         * connection timeout is reached.
         *
         * The connection state can be checked using isConnected().
         */
        void connect();

        /**
         * @brief Checks whether the MQTT client is connected.
         *
         * @return True if connected to the MQTT broker, false otherwise.
         */
        bool isConnected();

        /**
         * @brief Publishes a message to an MQTT topic.
         *
         * Attempts to establish an MQTT connection if disconnected.
         * Messages are published with QoS 1 and optionally retained
         * by the broker.
         *
         * @param topic MQTT topic to publish to.
         * @param payload Message payload.
         * @param retain Whether the broker should retain the message.
         * @return True if the MQTT client's publishing operation succeeds,
         *         false otherwise.
         */
        bool publish(const char* topic, const char* payload, bool retain);
        
        /**
         * @brief Subscribes to an MQTT topic.
         *
         * @param topic MQTT topic to subscribe to.
         * @return True if the subscription succeeds, false otherwise.
         */
        bool subscribe(const char* topic);

        /**
         * @brief Reads an incoming MQTT message.
         *
         * Checks for an available message and copies its topic and payload
         * into the provided buffers.
         *
         * On successful reads, both buffers are null-terminated.
         * Messages exceeding the available buffer capacity are truncated
         * without reporting an error.
         *
         * @param topic Buffer for the received MQTT topic.
         * @param topicSize Size of the topic buffer in bytes.
         * @param payload Buffer for the received message payload.
         * @param payloadSize Size of the payload buffer in bytes.
         * @return True if a message with a non-empty payload was read,
         *         false otherwise.
         */
        bool readMessage(char* topic, std::size_t topicSize, char* payload, std::size_t payloadSize);

        /**
         * @brief Disconnects the MQTT client from the broker.
         */
        void disconnect();
};