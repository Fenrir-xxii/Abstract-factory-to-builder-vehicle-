#include "VehicleMainParts.h"

// FUEL

void Fuel::info()
{
    std::cout << getTypeName() << " " << std::to_string(volume) << std::endl;
}

int Fuel::getVolume() 
{
    return volume;
}

void Fuel::use(int volume)
{
    if (this->volume - volume < 0) 
    {
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

//ENGINE

std::string StandardGasolineEngine::getName()
{
    return "Standard gasoline engine";
}

int StandardGasolineEngine::getSpeed(Fuel& fuel)
{
    if (fuel.getTypeName() != "GASOLINE") 
    {
        throw "Invalid fuel type";
    }
    fuel.use(10);
    return 100;
}

std::string StandardDieselEngine::getName()
{
    return "Standard diesel engine";
}

int StandardDieselEngine::getSpeed(Fuel& fuel)
{
    if (fuel.getTypeName() != "DIESEL") 
    {
        throw "Invalid fuel type";
    }
    fuel.use(20);
    return 200;
}

std::string TurboV8DieselEngine::getName()
{
    return "Turbo V8 diesel engine";
}

int TurboV8DieselEngine::getSpeed(Fuel& fuel)
{
    if (fuel.getTypeName() != "DIESEL") 
    {
        throw "Invalid fuel type";
    }
    fuel.use(20);
    return 180;
}

std::string StandardElectricEngine::getName()
{
    return "Standard electric engine";
}

int StandardElectricEngine::getSpeed(Fuel& fuel)
{
    if (fuel.getTypeName() != "ELECTRICITY") 
    {
        throw "Invalid fuel type";
    }
    fuel.use(20);
    return 90;
}

std::string StandardHybridEngine::getName()
{
    return "Standard hybrid engine";
}

int StandardHybridEngine::getSpeed(Fuel& fuel)
{
    if (fuel.getTypeName() != "ELECTRICITY" and fuel.getTypeName() != "GASOLINE") 
    {
        throw "Invalid fuel type";
    }
    fuel.use(20);
    return 180;
}