#include <unity.h>

void setUp()
{

}

void tearDown()
{

}


// BatterySensor
void test_battery_voltage_not_initialized_should_be_not_initialized();
void test_battery_voltage_measurement_error_should_be_not_initialized();
void test_battery_voltage_empty_should_be_battery_level_min();
void test_battery_voltage_full_should_be_battery_level_max();
void test_battery_voltage_middle_should_be_battery_level_50_percent();
void test_battery_voltage_below_empty_should_be_battery_level_min();
void test_battery_voltage_above_full_should_be_battery_level_max();


int main() {
    UNITY_BEGIN();

    // BatterySensor
    RUN_TEST(test_battery_voltage_not_initialized_should_be_not_initialized);
    RUN_TEST(test_battery_voltage_measurement_error_should_be_not_initialized);
    RUN_TEST(test_battery_voltage_empty_should_be_battery_level_min);
    RUN_TEST(test_battery_voltage_full_should_be_battery_level_max);
    RUN_TEST(test_battery_voltage_middle_should_be_battery_level_50_percent);
    RUN_TEST(test_battery_voltage_below_empty_should_be_battery_level_min);
    RUN_TEST(test_battery_voltage_above_full_should_be_battery_level_max);

    return UNITY_END();
}