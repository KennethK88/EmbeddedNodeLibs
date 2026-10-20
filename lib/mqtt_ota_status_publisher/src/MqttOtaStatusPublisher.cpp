#include "MqttOtaStatusPublisher.h"

namespace
{
    const char* otaStatusTopicTarget = MQTT_BASE_TOPIC "/ota/status";
}

bool MqttOtaStatusPublisher::publishWindowOpen()
{
    return mqttClientService.publish(otaStatusTopicTarget, "window_open", true);
}

bool MqttOtaStatusPublisher::publishWindowClosed()
{
    return mqttClientService.publish(otaStatusTopicTarget, "window_closed", true);
}