#pragma once
#include <iostream>
#include <string>

// WHEELS

class Wheels
{
public:
    void info();
    virtual std::string getName() = 0;
    virtual int getMaxSpeed() = 0;
};

class StandardWheels : public Wheels
{
public:
    std::string getName() override;
    int getMaxSpeed() override;
};

class SpeedWheels : public Wheels
{
public:
    std::string getName() override;
    int getMaxSpeed() override;
};

class ReinforcedWheels : public Wheels
{
public:
    std::string getName() override;
    int getMaxSpeed() override;
};

// AIR CONDITIONER

class AirConditioner 
{
public:
    virtual void info() = 0;
};

class TwoZoneClimateControl : public AirConditioner 
{
public:
    TwoZoneClimateControl() : AirConditioner() {}

    void info() override;
};

// AUDIO

class Audio 
{
public:
    virtual void info() = 0;
};

class HiFiAudioSystem : public Audio 
{
public:
    HiFiAudioSystem() : Audio() {}

    void info() override;
};

class MarineAudioSystem : public Audio
{
public:
    MarineAudioSystem() : Audio() {}

    void info() override;
};

//PROPELLER

class Propeller
{
public:
    void info();
    virtual std::string getName() = 0;
    virtual int getMaxSpeed() = 0;
};

class FourBladePropeller : public Propeller
{
public:
    FourBladePropeller() : Propeller() {}

    std::string getName() override;
    int getMaxSpeed() override;
};