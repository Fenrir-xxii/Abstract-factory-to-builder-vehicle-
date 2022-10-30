#pragma once
#include "Vehicle.h"
#include "Fuel.h"
#include "Wheels.h"
#include "Engine.h"
#include "Menu.h"

class Truck : public Vehicle
{
    Engine* engine;
    Wheels* wheels;
    Fuel* fuel;
    std::string name;
public:
    Truck(Engine* engine, Wheels* wheels, Fuel* fuel, std::string name, int qtyOfWheels) : Vehicle(engine, wheels, fuel, name, qtyOfWheels) {}

    ~Truck()
    {
        delete engine;
        delete wheels;
        delete fuel;
    }
};

class TruckPartsFactory : public VehiclePartsFactory
{
public:
    // some specific methods only for car
    std::string getName() override;
    int getQtyOfWheels() override;
};

class DieselTruckPartsFactory : public TruckPartsFactory
{
public:
    Engine* createEngine() override;
    Fuel* createFuel(int volume) override;
    Wheels* createWheels() override;
};
