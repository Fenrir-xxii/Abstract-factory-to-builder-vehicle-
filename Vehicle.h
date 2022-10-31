#pragma once
#include "VehicleMainParts.h"
#include "VehicleOptionalParts.h"

class Vehicle
{
protected:
	int qtyOfWheels;
	std::string name;
	Engine* engine;
	Wheels* wheels;
	Fuel* fuel;
	AirConditioner* airConditioner = nullptr;
	Audio* audio = nullptr;
	Propeller* propeller = nullptr;
public:
	Vehicle() {}
	
	/*Vehicle(Engine* engine, Wheels* wheels, Fuel* fuel, AirConditioner* airConditioner, Audio* audio, std::string name, int qtyOfWheels)
	{
		this->engine = engine;
		this->wheels = wheels;
		this->fuel = fuel;
		this->audio = audio;
		this->airConditioner = airConditioner;
		this->name = name;
		this->qtyOfWheels = qtyOfWheels;
	}*/

	virtual void drive();
	virtual void info();
	void setEngine(Engine* engine);
	void setWheels(Wheels* wheels);
	void setFuel(Fuel* fuel);
	void setAirConditioner(AirConditioner* airConditioner);
	void setAudio(Audio* audio);
	void setPropeller(Propeller* propeller);

	~Vehicle()
	{
		delete engine;
		delete wheels;
		delete fuel;
		delete airConditioner;
		delete audio;
		delete propeller;
	}
};

//FACTORY

class VehiclePartsFactory 
{
public:
	//std::string name;
	//int qtyOfWheels;

	virtual std::string getName() = 0;
	virtual int getQtyOfWheels() = 0;
	virtual Engine* createEngine() = 0;
	virtual Fuel* createFuel(int volume) = 0;
	virtual Wheels* createWheels() = 0;
};

//BUILDER

class VehicleBuilder
{
protected:
	Vehicle* vehicle;
public:
	VehicleBuilder() 
	{
		start();
	}

	virtual VehicleBuilder* start();
	virtual VehicleBuilder* makeRequired() = 0;
	virtual VehicleBuilder* makeOptions() = 0;

	Vehicle* getResult() 
	{
		return vehicle;
	}
};