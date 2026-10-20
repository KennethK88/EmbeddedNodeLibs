#pragma once
#include <MqttClientService.h>

class MqttOtaStatusPublisher
{
    private:
        MqttClientService& mqttClientService;

    public:
        explicit MqttOtaStatusPublisher(MqttClientService& mqttClientService) : mqttClientService(mqttClientService) {}
        bool publishWindowOpen();
        bool publishWindowClosed();
};