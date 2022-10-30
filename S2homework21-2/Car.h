#pragma once
#include "Fuel.h"
#include "Wheels.h"
#include "Engine.h"
#include "Menu.h"

class Car {
    Engine* engine;
    Wheels* wheels;
    Fuel* fuel;
public:
    Car(Engine* engine, Wheels* wheels, Fuel* fuel) {
        this->engine = engine;
        this->wheels = wheels;
        this->fuel = fuel;
    }

    void drive();
    void info();

    ~Car() {
        delete engine;
        delete wheels;
        delete fuel;
    }
};

class CarPartsFactory {
public:
    virtual Engine* createEngine() = 0;
    virtual Fuel* createFuel(int volume) = 0;
    virtual Wheels* createWheels() = 0;
};

class GasolineCarPartsFactory : public CarPartsFactory {
public:
    Engine* createEngine() override;
    Fuel* createFuel(int volume) override;
    Wheels* createWheels() override;
};

class DieselCarPartsFactory : public CarPartsFactory {
public:
    Engine* createEngine() override;
    Fuel* createFuel(int volume) override;
    Wheels* createWheels() override;
};

class ElectricCarPartsFactory : public CarPartsFactory {
public:
    Engine* createEngine() override;
    Fuel* createFuel(int volume) override;
    Wheels* createWheels() override;
};

class HybridCarPartsFactory : public CarPartsFactory {
public:
    Engine* createEngine() override;
    Fuel* createFuel(int volume) override;
    Wheels* createWheels() override;
};