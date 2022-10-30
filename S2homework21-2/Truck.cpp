#include "Truck.h"

std::string TruckPartsFactory::getName()
{
    return "Truck";
}
int TruckPartsFactory::getQtyOfWheels()
{
    return 18;
}

Engine* DieselTruckPartsFactory::createEngine()
{
    return new TurboV8DieselEngine();
}

Fuel* DieselTruckPartsFactory::createFuel(int volume)
{
    return new Diesel(volume);
}

Wheels* DieselTruckPartsFactory::createWheels()
{
    return new ReinforcedWheels();
}
