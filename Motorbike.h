#pragma once
#include "Vehicle.h"
#include "Menu.h"

class Motorbike : public Vehicle 
{
public:
    Motorbike()
    {
        this->name = "Motorbike";
        this->qtyOfWheels = 2;
    }

    void info() override;
    void drawName();

    ~Motorbike() 
    {
        delete engine;
        delete wheels;
        delete fuel;
    }
};

//FACTORY

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

//BUILDER

class MotorbikeBuilder : public VehicleBuilder
{
public:
    MotorbikeBuilder()
    {
        start();
    }

    VehicleBuilder* start() override;
};

class GasolineMotorbikeBuilder : public MotorbikeBuilder 
{
public:
    GasolineMotorbikeBuilder() : MotorbikeBuilder() {}

    VehicleBuilder* makeRequired() override;
    VehicleBuilder* makeOptions() override;
};