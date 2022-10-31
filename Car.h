#pragma once
#include "Vehicle.h"
#include "Menu.h"

class Car : public Vehicle
{
public:
    Car() 
    {
        this->name = "Car";
        this->qtyOfWheels = 4;
    }
    
    void info() override;
    void drawName();

    ~Car() 
    {
        delete engine;
        delete wheels;
        delete fuel;
    }
};

//FACTORY

class CarPartsFactory : public VehiclePartsFactory
{
public:
  // some specific methods only for car
    std::string getName() override;
    int getQtyOfWheels() override;
};

class GasolineCarPartsFactory : public CarPartsFactory
{
public:
    Engine* createEngine() override;
    Fuel* createFuel(int volume) override;
    Wheels* createWheels() override;
};

class DieselCarPartsFactory : public CarPartsFactory
{
public:
    Engine* createEngine() override;
    Fuel* createFuel(int volume) override;
    Wheels* createWheels() override;
};

class ElectricCarPartsFactory : public CarPartsFactory
{
public:
    Engine* createEngine() override;
    Fuel* createFuel(int volume) override;
    Wheels* createWheels() override;
};

class HybridCarPartsFactory : public CarPartsFactory
{
public:
    Engine* createEngine() override;
    Fuel* createFuel(int volume) override;
    Wheels* createWheels() override;
};

//BUILDER

class CarBuilder : public VehicleBuilder
{
public:
    CarBuilder()
    {
        start();
    }

    VehicleBuilder* start() override;
};

class GasolineCarStandardBuilder : public CarBuilder 
{
public:
    GasolineCarStandardBuilder() : CarBuilder() {}

    VehicleBuilder* makeRequired() override;
    VehicleBuilder* makeOptions() override;

};

class GasolineCarDeluxeBuilder : public GasolineCarStandardBuilder 
{
public:
    GasolineCarDeluxeBuilder() : GasolineCarStandardBuilder() {}

    VehicleBuilder* makeOptions() override;
};