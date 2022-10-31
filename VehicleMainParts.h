#pragma once

#include <iostream>
#include <string>

// FUEL

class Fuel
{
protected:
    int volume;
public:
    Fuel(int volume)
    {
        this->volume = volume;
    }

    void info();
    int getVolume();
    void use(int volume);
    virtual std::string getTypeName() = 0;
};

class Gasoline : public Fuel
{
public:
    Gasoline(int volume) : Fuel(volume) {}

    std::string getTypeName() override;
};

class Diesel : public Fuel
{
public:
    Diesel(int volume) : Fuel(volume) {}

    std::string getTypeName() override;
};

class Electricity : public Fuel
{
public:
    Electricity(int volume) : Fuel(volume) {}

    std::string getTypeName() override;
};


//ENGINE

class Engine 
{
public:
    void info() {
        std::cout << getName() << std::endl;
    }

    virtual std::string getName() = 0;
    virtual int getSpeed(Fuel& fuel) = 0;
};

class StandardGasolineEngine : public Engine 
{
public:
    std::string getName() override;
    int getSpeed(Fuel& fuel) override;
};

class StandardDieselEngine : public Engine 
{
public:
    std::string getName() override;
    int getSpeed(Fuel& fuel) override;
};

class TurboV8DieselEngine : public Engine 
{
public:
    std::string getName() override;
    int getSpeed(Fuel& fuel) override;
};

class StandardElectricEngine : public Engine 
{
public:
    std::string getName() override;
    int getSpeed(Fuel& fuel) override;
};

class StandardHybridEngine : public Engine 
{
public:
    std::string getName() override;
    int getSpeed(Fuel& fuel) override;
};