#include "Fuel.h"

void Fuel::info()
{
    std::cout << getTypeName() << " " << std::to_string(volume) << std::endl;
}

int Fuel::getVolume() {
    return volume;
}

void Fuel::use(int volume)
{
    if (this->volume - volume < 0) {
        throw "FUEL RAN OUT";
    }
    this->volume -= volume;
}

std::string Gasoline::getTypeName()
{
    return "GASOLINE";
};

std::string Diesel::getTypeName() 
{
    return "DIESEL";
};

std::string Electricity::getTypeName()
{
    return "ELECTRICITY";
};