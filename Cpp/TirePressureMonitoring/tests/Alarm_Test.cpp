#include <gmock/gmock.h>
#include "Alarm.h"

namespace {
    class MockSensor : public ISensor {
    public:
        MockSensor(double value) : m_value(value) {}
        virtual ~MockSensor() {}
        virtual double popNextPressurePsiValue() override { return m_value; }
    private:
        double m_value;
    };
    TEST(Alarm, SensorBelowThresholdShouldGiveAlarm) {
        std::unique_ptr<ISensor> sensor(new MockSensor(0));
        Alarm alarm(sensor);
        alarm.check();
        ASSERT_TRUE(alarm.isAlarmOn());
    }
    TEST(Alarm, SensorOverThresholdShouldGiveAlarm) {
        std::unique_ptr<ISensor> sensor(new MockSensor(22));
        Alarm alarm(sensor);
        alarm.check();
        ASSERT_TRUE(alarm.isAlarmOn());
    }
    TEST(Alarm, SensorInRangeShouldntGiveAlarm) {
        std::unique_ptr<ISensor> sensor(new MockSensor(20));
        Alarm alarm(sensor);
        alarm.check();
        ASSERT_FALSE(alarm.isAlarmOn());
    }
}
