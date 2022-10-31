#include "Boat.h"

void Boat::info()
{
    system("cls");
    drawName();
    //std::cout << "Inside boat:\n";
    std::cout << "Vehicle type: " << this->name << std::endl;
    engine->info();
    std::cout << "Fuel: ";
    fuel->info();
    propeller->info();
    std::cout << qtyOfWheels << " propeller(s)." << std::endl;
    if (airConditioner != nullptr) {
        airConditioner->info();
    }
    if (audio != nullptr) {
        audio->info();
    }
}

void Boat::drive()
{
    int speed = engine->getSpeed(*fuel);
    if (speed > propeller->getMaxSpeed()) 
    {
        throw "PROPELLER FELL OFF";
    }
}

void Boat::drawName()
{
    std::vector<COORD> coordinates({ {1,0} ,{2,0}, {3,0}, {8,0}, {9,0}, {14,0}, {15,0}, {19,0}, {20,0}, {21,0}, {22,0}, {23,0},
                                    {1,1}, {4,1}, {7,1}, {10,1}, {13,1}, {16,1}, {21,1},
                                    {1,2}, {2,2}, {3,2}, {7,2}, {10,2}, {13,2}, {16,2}, {21,2},
                                    {1,3}, {4,3}, {7,3}, {10,3}, {13,3}, {14,3}, {15,3}, {16,3}, {21,3},
                                    {1,4}, {2,4}, {3,4}, {8,4}, {9,4}, {13,4}, {16,4}, {21,4} });

    SetColor(BLACK, BLUE_FADE);
    for (int i = 0; i < coordinates.size(); i++)
    {
        SetCursorPosition(coordinates[i]);
        std::cout << ' ';
    }
    SetColor(WHITE, BLACK);
    std::cout << std::endl << std::endl;
}

//FACTORY

std::string TruckPartsFactory::getName()
{
    return "Truck";
}
int TruckPartsFactory::getQtyOfWheels()
{
    return 18;
}

Engine* DieselTruckPartsFactory::createEngine()
{
    return new TurboV8DieselEngine();
}

Fuel* DieselTruckPartsFactory::createFuel(int volume)
{
    return new Diesel(volume);
}

Wheels* DieselTruckPartsFactory::createWheels()
{
    return new ReinforcedWheels();
}

//BUILDER

VehicleBuilder* BoatBuilder::start()
{
    delete vehicle;
    vehicle = new Boat();
    return this;
}

VehicleBuilder* DieselBoatStandardBuilder::makeRequired()
{
    vehicle->setEngine(new TurboV8DieselEngine());
    vehicle->setFuel(new Diesel(100));
    vehicle->setPropeller(new FourBladePropeller());
    return this;
}

VehicleBuilder* DieselBoatStandardBuilder::makeOptions()
{
    vehicle->setAirConditioner(nullptr);
    vehicle->setAudio(new MarineAudioSystem());
    return this;
}