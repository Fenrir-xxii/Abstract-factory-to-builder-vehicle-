#include "Vehicle.h"

void Vehicle::drive()
{
    int speed = engine->getSpeed(*fuel);
    if (speed > wheels->getMaxSpeed()) 
    {
        throw "WHEELS FELL OFF";
    }
}

void Vehicle::info()
{
    system("cls");
    //std::cout << "Inside vehicle:\n";
    std::cout << "Vehicle type: " << this->name << std::endl;
    engine->info();
    std::cout << "Fuel: ";
    fuel->info();
    wheels->info();
    std::cout << qtyOfWheels << " wheels." << std::endl;
    if (airConditioner != nullptr) {
        airConditioner->info();
    }
    if (audio != nullptr) {
        audio->info();
    }
}

void Vehicle::setEngine(Engine* engine)
{
	this->engine = engine;
}

void Vehicle::setWheels(Wheels* wheels)
{
	this->wheels = wheels;
}

void Vehicle::setFuel(Fuel* fuel)
{
	this->fuel = fuel;
}

void Vehicle::setAirConditioner(AirConditioner* airConditioner)
{
	this->airConditioner = airConditioner;
}

void Vehicle::setAudio(Audio* audio)
{
	this->audio = audio;
}

void Vehicle::setPropeller(Propeller* propeller)
{
	this->propeller = propeller;
}

VehicleBuilder* VehicleBuilder::start()
{
    vehicle = new Vehicle();
    return this;
}