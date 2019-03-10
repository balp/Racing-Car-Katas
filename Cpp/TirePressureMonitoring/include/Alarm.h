#pragma once
#include <memory>

#include "Sensor.h"

class Alarm
{
public:
    Alarm(std::unique_ptr<ISensor>& sensor);
    void check();
    bool isAlarmOn();

protected:
    std::unique_ptr<ISensor> m_sensor;
    double m_lowPressureThreshold;
    double m_highPressureThreshold;
    bool m_alarmOn;
};
