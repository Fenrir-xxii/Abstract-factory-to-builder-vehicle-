#pragma once
#include "Engine.h"
#include "Fuel.h"
#include "Wheels.h"

class Vehicle
{
protected:
	int qtyOfWheels;
	Engine* engine;
	Wheels* wheels;
	Fuel* fuel;
	std::string name;
public:
	Vehicle(Engine* engine, Wheels* wheels, Fuel* fuel, std::string name, int qtyOfWheels)
	{
		this->engine = engine;
		this->wheels = wheels;
		this->fuel = fuel;
		this->name = name;
		this->qtyOfWheels = qtyOfWheels;

	}

	void drive();
	void info();

	~Vehicle()
	{
		delete engine;
		delete wheels;
		delete fuel;
	}
};

class VehiclePartsFactory 
{
public:
	std::string name;
	int qtyOfWheels;

	virtual std::string getName() = 0;
	virtual int getQtyOfWheels() = 0;
	virtual Engine* createEngine() = 0;
	virtual Fuel* createFuel(int volume) = 0;
	virtual Wheels* createWheels() = 0;
};