#pragma once
#include "Vehicle.h"
#include "Fuel.h"
#include "Wheels.h"
#include "Engine.h"

class Motorbike : public Vehicle 
{
    Engine* engine;
    Wheels* wheels;
    Fuel* fuel;
public:
    Motorbike(Engine* engine, Wheels* wheels, Fuel* fuel, std::string name, int qtyOfWheels) : Vehicle(engine, wheels, fuel, name, qtyOfWheels) {}

    ~Motorbike() 
    {
        delete engine;
        delete wheels;
        delete fuel;
    }
};

class MotorbikePartsFactory : public VehiclePartsFactory
{
public:
    // some specific methods only for motorbike
    std::string getName() override;
    int getQtyOfWheels() override;
};

class GasolineMotorbikePartsFactory : public MotorbikePartsFactory
{
public:
    Engine* createEngine() override;
    Fuel* createFuel(int volume) override;
    Wheels* createWheels() override;
};

class DieselMotorbikePartsFactory : public MotorbikePartsFactory
{
public:
    Engine* createEngine() override;
    Fuel* createFuel(int volume) override;
    Wheels* createWheels() override;
};

class ElectricMotorbikePartsFactory : public MotorbikePartsFactory
{
public:
    Engine* createEngine() override;
    Fuel* createFuel(int volume) override;
    Wheels* createWheels() override;
};