#pragma once

#include <cstdint>

/**
 * @file BatteryTypes.h
 * @brief Defines common data types for battery measurement and processing.
 */

/**
 * @brief Represents a battery voltage in volts.
 */
using BatteryVoltage = float;

/**
 * @brief Represents a battery level in percent.
 *
 * Valid battery levels range from 0 to 100.
 * The special value 255 represents an uninitialized battery level.
 */
using BatteryLevel = std::uint8_t;

/**
 * @brief Represents a GPIO pin used for analog-to-digital conversion.
 */
using AdcPin = std::uint8_t;