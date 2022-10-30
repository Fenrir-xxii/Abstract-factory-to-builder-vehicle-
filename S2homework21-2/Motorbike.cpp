#include "Motorbike.h"

std::string MotorbikePartsFactory::getName()
{
    return "Motobike";
}
int MotorbikePartsFactory::getQtyOfWheels()
{
    return 2;
}

Engine* GasolineMotorbikePartsFactory::createEngine()
{
    return new StandardGasolineEngine();
}

Fuel* GasolineMotorbikePartsFactory::createFuel(int volume)
{
    return new Gasoline(volume);
}

Wheels* GasolineMotorbikePartsFactory::createWheels()
{
    return new SpeedWheels();
}

Engine* DieselMotorbikePartsFactory::createEngine()
{
    return new StandardDieselEngine();
}

Fuel* DieselMotorbikePartsFactory::createFuel(int volume)
{
    return new Diesel(volume);
}

Wheels* DieselMotorbikePartsFactory::createWheels()
{
    return new SpeedWheels();
}

Engine* ElectricMotorbikePartsFactory::createEngine()
{
    return new StandardElectricEngine();
}

Fuel* ElectricMotorbikePartsFactory::createFuel(int volume)
{
    return new Electricity(volume);
}

Wheels* ElectricMotorbikePartsFactory::createWheels()
{
    return new StandardWheels();
}