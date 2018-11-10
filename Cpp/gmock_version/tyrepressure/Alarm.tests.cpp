#include "Alarm.hpp"
#include "StubSensor.hpp"
#include <gmock/gmock.h>

using namespace ::testing;

namespace {

    class AlarmTest : public ::testing::Test {
        protected:
            AlarmTest() : alarm(&stubSensor) {}
            StubSensor stubSensor;
            Alarm alarm;

            void verifySensor(int value, bool expected) {
                EXPECT_CALL(stubSensor, popNextPressurePsiValue()).WillOnce(Return(value));

                alarm.check();

                ASSERT_EQ(alarm.isAlarmOn(), expected);
            }

    };

    TEST_F(AlarmTest, LowPreasure16)
    {
        verifySensor(16, true);
    }

    TEST_F(AlarmTest, OkPreasure20)
    {
        EXPECT_CALL(stubSensor, popNextPressurePsiValue()).WillOnce(Return(20));

        alarm.check();

        ASSERT_FALSE(alarm.isAlarmOn());
    }


}
