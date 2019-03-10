
#include <utility>
#include <memory>
#include "../include/Alarm.h"

Alarm::Alarm(std::unique_ptr<ISensor>& sensor) :
    m_sensor(std::move(sensor)),
    m_lowPressureThreshold(17),
    m_highPressureThreshold(21),
    m_alarmOn(false)
{}

void Alarm::check()
{
    double psiPressureValue = m_sensor->popNextPressurePsiValue();

    if (psiPressureValue < m_lowPressureThreshold || m_highPressureThreshold < psiPressureValue)
    {
        m_alarmOn = true;
    }
}

bool Alarm::isAlarmOn()
{
    return m_alarmOn;
}
