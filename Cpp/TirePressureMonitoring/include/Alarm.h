#pragma once

#include <memory>
#include "Sensor.h"

class Alarm
{
public:
    Alarm(std::shared_ptr<ISensor> sensor);
    void check();
    bool isAlarmOn();

protected:
    std::shared_ptr<ISensor> m_sensor;
    double m_lowPressureThreshold;
    double m_highPressureThreshold;
    bool m_alarmOn;
};
