#pragma once
#include "MqttClientService.h"

class MqttOtaRequestReader
{
    private:
        MqttClientService& mqttClientService;
        bool otaRequested = false;

    public:
        explicit MqttOtaRequestReader(MqttClientService& mqttClientService) : mqttClientService(mqttClientService) {}
        bool subscribe();
        bool isOtaRequested() const;
        bool processMessage(const char* topic, const char* payload);
};