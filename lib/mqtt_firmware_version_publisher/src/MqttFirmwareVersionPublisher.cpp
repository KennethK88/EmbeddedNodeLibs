#include "MqttFirmwareVersionPublisher.h"

namespace
{
    constexpr const char* firmwareVersion = FIRMWARE_VERSION;
    constexpr const char* firmwareVersionTopicTarget = MQTT_BASE_TOPIC "/firmware/version";
}

bool MqttFirmwareVersionPublisher::publishFirmwareVersion()
{
    return mqttClientService.publish(firmwareVersionTopicTarget, firmwareVersion, true);
}