#pragma once
#include "Vehicle.h"
#include "Menu.h"

class Boat : public Vehicle
{
public:
    Boat()
    {
        this->name = "Boat";
        this->qtyOfWheels = 1;  //propeller
    }

    void info() override;
    void drive() override;
    void drawName();

    ~Boat()
    {
        delete engine;
        delete wheels;
        delete fuel;
    }
};

//FACTORY

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

//BUILDER

class BoatBuilder : public VehicleBuilder
{
public:
    BoatBuilder()
    {
        start();
    }

    VehicleBuilder* start() override;
};

class DieselBoatStandardBuilder : public BoatBuilder 
{
public:
    DieselBoatStandardBuilder() : BoatBuilder() {}

    VehicleBuilder* makeRequired() override;
    VehicleBuilder* makeOptions() override;
};