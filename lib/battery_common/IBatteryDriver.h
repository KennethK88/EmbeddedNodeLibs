#pragma once

#include "BatteryTypes.h"

/**
 * @file IBatteryDriver.h
 * @brief Defines the interface for battery voltage measurement drivers.
 */

/**
 * @brief Interface for hardware-specific battery voltage measurement.
 *
 * Provides a hardware-independent abstraction for initializing
 * a battery measurement driver, acquiring voltage measurements,
 * and retrieving the most recently measured voltage.
 */
class IBatteryDriver
{
    public:
        virtual ~IBatteryDriver() = default;

        /**
         * @brief Initializes the battery voltage measurement hardware.
         */
        virtual void init() = 0;

        /**
         * @brief Reads the battery voltage and updates the stored measurement.
         */
        virtual void readVoltage() = 0;

        /**
         * @brief Returns the most recently measured battery voltage.
         *
         * @return Battery voltage in volts, or a special value defined
         *         in BatteryConstants if no valid measurement is available.
         */        
        virtual BatteryVoltage getVoltage() const = 0;
};