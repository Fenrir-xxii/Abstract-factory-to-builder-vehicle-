#pragma once
#include "Fuel.h"

class Engine {
public:
    void info() {
        std::cout << getName() << std::endl;
    }

    virtual std::string getName() = 0;
    virtual int getSpeed(Fuel& fuel) = 0;
};

class StandardGasolineEngine : public Engine {
public:
    std::string getName() override;
    int getSpeed(Fuel& fuel) override;
};

class StandardDieselEngine : public Engine {
public:
    std::string getName() override;
    int getSpeed(Fuel& fuel) override;
};

class StandardElectricEngine : public Engine {
public:
    std::string getName() override;
    int getSpeed(Fuel& fuel) override;
};

class StandardHybridEngine : public Engine {
public:
    std::string getName() override;
    int getSpeed(Fuel& fuel) override;
};