#pragma once
#include <cstdint>

/**
 * @brief Battery voltage value in volts.
 */
using BatteryVoltage = float;

/**
 * @brief Battery level value in percent.
 *
 * Valid battery level values are in the range from 0 to 100.
 * Special values such as 255 may be used to indicate invalid or uninitialized states.
 */
using BatteryLevel = std::uint8_t;

/**
 * @brief GPIO pin used as an analog-to-digital converter input.
 */
using AdcPin = std::uint8_t;