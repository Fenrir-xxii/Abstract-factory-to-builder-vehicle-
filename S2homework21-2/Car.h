#pragma once
#include "Vehicle.h"
#include "Fuel.h"
#include "Wheels.h"
#include "Engine.h"
#include "Menu.h"

class Car : public Vehicle
{
    Engine* engine;
    Wheels* wheels;
    Fuel* fuel;
    std::string name;
public:
    Car(Engine* engine, Wheels* wheels, Fuel* fuel, std::string name, int qtyOfWheels) : Vehicle(engine, wheels, fuel, name, qtyOfWheels) {}

    ~Car() 
    {
        delete engine;
        delete wheels;
        delete fuel;
    }
};

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