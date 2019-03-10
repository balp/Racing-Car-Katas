#define CATCH_CONFIG_MAIN
#include <memory>
#include "catch2/catch.hpp"

#include "Alarm.h"
#include "Sensor.h"

namespace {
    class MockSensor : public ISensor
    {
        private:
            double m_value;
        public:
            MockSensor() : m_value(0) {}
            virtual ~MockSensor() {}
            virtual double popNextPressurePsiValue() override { return m_value; }
            void setValue(double value) { m_value = value; }
    };
}

SCENARIO( "Alarm should be sounded when sensor values are out of range", "[Alarm]" ) {
    GIVEN( "an Alarm class" ) {
        std::shared_ptr<MockSensor> sensor(new MockSensor());
        Alarm alarm(sensor);
        WHEN( "the monitor reports < 17" ) {
            sensor->setValue(15);
            alarm.check();
            THEN( "the alarm should be active" ) {
                REQUIRE(alarm.isAlarmOn() == true);
            }
        }
        WHEN( "the monitor reports between 17 and 21" ) {
            sensor->setValue(19);
            alarm.check();
            THEN( "the alarm should be inactive" ) {
                REQUIRE(alarm.isAlarmOn() == false);
            }
        }
        WHEN( "the monitor reports > 21" ) {
            sensor->setValue(22);
            alarm.check();
            THEN( "the alarm should be active" ) {
                REQUIRE(alarm.isAlarmOn() == true);
            }
        }
    }
}
