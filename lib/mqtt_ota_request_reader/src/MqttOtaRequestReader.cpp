#include "MqttOtaRequestReader.h"

#include <cstring>

namespace
{
    const char* otaRequestTopicTarget = MQTT_BASE_TOPIC "/ota/request";
}

bool MqttOtaRequestReader::subscribe()
{
    return mqttClientService.subscribe(otaRequestTopicTarget);
}

bool MqttOtaRequestReader::isOtaRequested() const
{
    return otaRequested;
}

bool MqttOtaRequestReader::processMessage(const char* topic, const char* payload)
{
    if (topic == nullptr) return false;
    if (payload == nullptr) return false;

    if (strcmp(topic, otaRequestTopicTarget) != 0) return false;
    if (strcmp(payload, "true") == 0) otaRequested = true;
    else if (strcmp(payload, "false") == 0) otaRequested = false;
    else return false;

    return true;
}