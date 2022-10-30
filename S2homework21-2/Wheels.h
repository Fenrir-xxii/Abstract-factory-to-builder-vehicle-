#pragma once
#include <iostream>
#include <string>

class Wheels {
public:
    void info() {
        std::cout << getName() << " max speed " << std::to_string(getMaxSpeed()) << std::endl;
    }

    virtual std::string getName() = 0;
    virtual int getMaxSpeed() = 0;
};

class StandardWheels : public Wheels {
public:
    std::string getName() override;
    int getMaxSpeed() override;
};

class SpeedWheels : public Wheels {
public:
    std::string getName() override;
    int getMaxSpeed() override;
};