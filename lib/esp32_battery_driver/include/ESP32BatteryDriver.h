#pragma once

#include <IBatteryDriver.h>
#include <BatteryTypes.h>
#include <BatteryConstants.h>

/**
 * @file ESP32BatteryDriver.h
 * @brief Defines an ESP32-specific driver for battery voltage measurement.
 */

/**
 * @brief Implements battery voltage measurement using the ESP32 ADC.
 *
 * Provides a hardware-specific implementation of the IBatteryDriver
 * interface.
 *
 * The driver reads the battery voltage through an analog input,
 * applies the configured voltage divider factor, and stores the
 * resulting voltage internally.
 *
 * The stored voltage can be used by higher-level components such
 * as BatterySensor to calculate the battery level.
 *
 * @note Before the first measurement, getVoltage() returns
 *       BatteryConstants::BATTERY_VOLTAGE_NOT_INITIALIZED.
 */
class ESP32BatteryDriver : public IBatteryDriver
{
    private:
        BatteryVoltage batteryVoltage = BatteryConstants::BATTERY_VOLTAGE_NOT_INITIALIZED;
        const AdcPin adcPin;
        const float voltageDividerFactor;
        
    public:

        /**
         * @brief Constructs an ESP32 battery voltage measurement driver.
         *
         * @param adcPin GPIO pin used for ADC measurements.
         * @param voltageDividerFactor Factor used to calculate the actual
         *                             battery voltage from the measured voltage.
         */
        explicit ESP32BatteryDriver(AdcPin adcPin, float voltageDividerFactor) : adcPin(adcPin), voltageDividerFactor(voltageDividerFactor) {}

        /**
         * @brief Configures the ADC pin attenuation to ADC_11db.
         */
        void init() override;

        /**
         * @brief Reads the battery voltage and updates the stored measurement.
         *
         * The measured voltage is converted to volts and adjusted using
         * the configured voltage divider factor.
         */
        void readVoltage() override;

        /**
         * @brief Returns the most recently measured battery voltage.
         *
         * Does not trigger a new measurement.
         *
         * @return Battery voltage in volts, or
         *         BatteryConstants::BATTERY_VOLTAGE_NOT_INITIALIZED
         *         if no measurement has been performed yet.
         */
        BatteryVoltage getVoltage() const override;
};