#include "ESP32BatteryDriver.h"

#include <Arduino.h>

namespace
{
    constexpr float MILLIVOLTS_TO_VOLTS = 0.001f;

    BatteryVoltage calculateBatteryVoltageFromPinMilliVolts(int adcPinVoltageMilliVolts, float voltageDividerFactor)
    {
        return (static_cast<BatteryVoltage>(adcPinVoltageMilliVolts * MILLIVOLTS_TO_VOLTS * voltageDividerFactor));
    }
}

void ESP32BatteryDriver::init()
{
    analogSetPinAttenuation(adcPin, ADC_11db);
}

void ESP32BatteryDriver::readVoltage()
{
    batteryVoltage = calculateBatteryVoltageFromPinMilliVolts(analogReadMilliVolts(adcPin), voltageDividerFactor);
}

BatteryVoltage ESP32BatteryDriver::getVoltage() const
{
    return batteryVoltage;
}