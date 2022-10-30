#pragma once
#include <iostream>
#include <string>

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