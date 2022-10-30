#include "Engine.h"

std::string StandardGasolineEngine::getName()
{
    return "Standard gasoline engine";
}

int StandardGasolineEngine::getSpeed(Fuel& fuel)
{
    if (fuel.getTypeName() != "GASOLINE") {
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
    if (fuel.getTypeName() != "DIESEL") {
        throw "Invalid fuel type";
    }
    fuel.use(20);
    return 200;
}

std::string StandardElectricEngine::getName()
{
    return "Standard electric engine";
}

int StandardElectricEngine::getSpeed(Fuel& fuel)
{
    if (fuel.getTypeName() != "ELECTRICITY") {
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
    if (fuel.getTypeName() != "ELECTRICITY" and fuel.getTypeName() != "GASOLINE") {
        throw "Invalid fuel type";
    }
    fuel.use(20);
    return 180;
}