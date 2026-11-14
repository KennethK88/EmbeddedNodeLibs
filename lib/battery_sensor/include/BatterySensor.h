#pragma once

#include <IBatteryDriver.h>

/**
 * @file BatterySensor.h
 * @brief Defines the application-level battery sensor.
 */

/**
 * @brief Provides battery level information based on measured battery voltage.
 *
 * Uses an IBatteryDriver to obtain battery voltage measurements
 * and calculate the corresponding battery level.
 *
 * The battery driver is referenced but not owned by this class.
 */
class BatterySensor
{
    private:
        IBatteryDriver& batteryDriver;

    public:

        /**
         * @brief Constructs a battery sensor using the specified battery driver.
         *
         * @param batteryDriver Reference to the battery driver.
         *                      The driver must outlive the BatterySensor instance.
         */
        BatterySensor(IBatteryDriver& batteryDriver) : batteryDriver(batteryDriver) {}

        /**
         * @brief Calculates the battery level from the last measured battery voltage.
         *
         * Uses the voltage provided by the battery driver and converts it
         * into a battery level percentage using a linear mapping.
         *
         * The calculated level is rounded and clamped to the range of 0 to 100.
         * This method does not trigger a new voltage measurement.
         *
         * @return Battery level in percent (0-100), or
         *         BatteryConstants::BATTERY_LEVEL_NOT_INITIALIZED if the
         *         voltage is uninitialized or indicates a measurement error.
         */
        BatteryLevel getBatteryLevel() const;
};