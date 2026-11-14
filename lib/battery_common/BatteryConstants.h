#pragma once

#include "BatteryTypes.h"

/**
 * @file BatteryConstants.h
 * @brief Defines constants for battery voltage and level processing.
 */

/**
 * @brief Provides constants for battery voltage measurements and battery levels.
 *
 * Includes voltage limits for linear battery level calculation,
 * valid battery level boundaries, and special values representing
 * measurement errors or uninitialized states.
 */
namespace BatteryConstants
{
    /// Battery voltage representing an empty battery in the linear level calculation.
    constexpr BatteryVoltage BATTERY_VOLTAGE_EMPTY = 3.0f;

    /// Battery voltage representing a fully charged battery in the linear level calculation.
    constexpr BatteryVoltage BATTERY_VOLTAGE_FULL = 4.2f;

    /// Special voltage value indicating a battery voltage measurement error.
    constexpr BatteryVoltage BATTERY_VOLTAGE_MEASUREMENT_ERROR = -999.0f;

    /// Special voltage value indicating that no battery voltage has been measured yet.
    constexpr BatteryVoltage BATTERY_VOLTAGE_NOT_INITIALIZED = -100.0f;

    /// Minimum valid battery level in percent.
    constexpr BatteryLevel BATTERY_LEVEL_MIN = 0;

    /// Maximum valid battery level in percent.
    constexpr BatteryLevel BATTERY_LEVEL_MAX = 100;

    /// Special battery level value outside the valid range, indicating an uninitialized state.
    constexpr BatteryLevel BATTERY_LEVEL_NOT_INITIALIZED = 255;
}