#include "BatterySensor.h"

#include <BatteryConstants.h>

#include <cmath>
#include <algorithm>

namespace
{
    float calculateLinearBatteryLevel(BatteryVoltage current, BatteryVoltage empty, BatteryVoltage full, float batteryLevelMin, float batteryLevelMax)
    {
        // prevent division by zero or invalid voltage range
        if (full <= empty) return batteryLevelMin;
        return batteryLevelMin + (current - empty) / (full - empty) * (batteryLevelMax - batteryLevelMin);
    }

    bool canCalculateBatteryLevel(BatteryVoltage current)
    {
        return ((current != BatteryConstants::BATTERY_VOLTAGE_MEASUREMENT_ERROR) && (current != BatteryConstants::BATTERY_VOLTAGE_NOT_INITIALIZED));
    }
}

BatteryLevel BatterySensor::getBatteryLevel() const
{
    BatteryVoltage currentBatteryVoltage = batteryDriver.getVoltage();

    if (!canCalculateBatteryLevel(currentBatteryVoltage)) return BatteryConstants::BATTERY_LEVEL_NOT_INITIALIZED;

    float batteryLevelMin = static_cast<float>(BatteryConstants::BATTERY_LEVEL_MIN);
    float batteryLevelMax = static_cast<float>(BatteryConstants::BATTERY_LEVEL_MAX);
    
    float batteryLevel = calculateLinearBatteryLevel(currentBatteryVoltage, BatteryConstants::BATTERY_VOLTAGE_EMPTY, BatteryConstants::BATTERY_VOLTAGE_FULL, batteryLevelMin, batteryLevelMax);

    return static_cast<BatteryLevel>(std::round(std::clamp(batteryLevel, batteryLevelMin, batteryLevelMax)));
}