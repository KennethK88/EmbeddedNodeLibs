#pragma once
#include <MqttClientService.h>

class MqttFirmwareVersionPublisher
{
    private:
        MqttClientService& mqttClientService;

    public:
        explicit MqttFirmwareVersionPublisher(MqttClientService& mqttClientService) : mqttClientService(mqttClientService) {}
        bool publishFirmwareVersion();
};