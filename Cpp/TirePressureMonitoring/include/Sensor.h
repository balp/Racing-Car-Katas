#pragma once

class ISensor
{
public:
    virtual ~ISensor() {}
    virtual double popNextPressurePsiValue() = 0;
};

class Sensor : public ISensor
{
public:
    Sensor();
    virtual ~Sensor() {}
    virtual double popNextPressurePsiValue() override;
};
