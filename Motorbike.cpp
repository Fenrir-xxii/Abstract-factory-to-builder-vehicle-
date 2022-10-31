#include "Motorbike.h"

void Motorbike::info()
{
    system("cls");
    drawName();
    //std::cout << "Inside motorbike:\n";
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

void Motorbike::drawName()
{
    std::vector<COORD> coordinates({ {1,0} ,{5,0}, {8,0}, {9,0}, {8,0} , {9,0}, {12,0}, {13,0}, {14,0}, {15,0}, {16,0}, {19,0}, {20,0}, {23,0}, {24,0}, {25,0}, {28,0}, {29,0}, {30,0}, {33,0}, {35,0}, {38,0}, {40,0}, {41,0}, {42,0},
                                    {1,1}, {2,1}, {4,1}, {5,1}, {7,1}, {10,1}, {14,1}, {18,1}, {21,1}, {23,1}, {26,1}, {28,1}, {31,1}, {33,1}, {35,1}, {37,1}, {40,1},
                                    {1,2}, {3,2}, {5,2}, {7,2}, {10,2}, {14,2}, {18,2}, {21,2}, {23,2}, {26,2}, {28,2}, {29,2}, {30,2}, {33,2}, {35,2}, {36,2}, {40,2}, {41,2},
                                    {1,3}, {5,3}, {7,3}, {10,3}, {14,3}, {18,3}, {21,3}, {23,3}, {24,3}, {25,3}, {28,3}, {31,3}, {33,3}, {35,3}, {37,3}, {40,3},
                                    {1,4}, {5,4}, {8,4}, {9,4}, {14,4}, {19,4}, {20,4}, {23,4}, {26,4}, {28,4}, {29,4}, {30,4}, {33,4}, {35,4}, {38,4}, {40,4}, {41,4}, {42,4} });

    SetColor(BLACK, RED_FADE);
    for (int i = 0; i < coordinates.size(); i++)
    {
        SetCursorPosition(coordinates[i]);
        std::cout << ' ';
    }
    SetColor(WHITE, BLACK);
    std::cout << std::endl << std::endl;
}

//FACTORY

std::string MotorbikePartsFactory::getName()
{
    return "Motobike";
}
int MotorbikePartsFactory::getQtyOfWheels()
{
    return 2;
}

Engine* GasolineMotorbikePartsFactory::createEngine()
{
    return new StandardGasolineEngine();
}

Fuel* GasolineMotorbikePartsFactory::createFuel(int volume)
{
    return new Gasoline(volume);
}

Wheels* GasolineMotorbikePartsFactory::createWheels()
{
    return new SpeedWheels();
}

Engine* DieselMotorbikePartsFactory::createEngine()
{
    return new StandardDieselEngine();
}

Fuel* DieselMotorbikePartsFactory::createFuel(int volume)
{
    return new Diesel(volume);
}

Wheels* DieselMotorbikePartsFactory::createWheels()
{
    return new SpeedWheels();
}

Engine* ElectricMotorbikePartsFactory::createEngine()
{
    return new StandardElectricEngine();
}

Fuel* ElectricMotorbikePartsFactory::createFuel(int volume)
{
    return new Electricity(volume);
}

Wheels* ElectricMotorbikePartsFactory::createWheels()
{
    return new StandardWheels();
}

//BUILDER

VehicleBuilder* MotorbikeBuilder::start()
{
    delete vehicle;
    vehicle = new Motorbike();
    return this;
}

VehicleBuilder* GasolineMotorbikeBuilder::makeRequired()
{
    vehicle->setEngine(new StandardGasolineEngine());
    vehicle->setFuel(new Gasoline(100));
    vehicle->setWheels(new StandardWheels());
    return this;
}

VehicleBuilder* GasolineMotorbikeBuilder::makeOptions()
{
    vehicle->setAirConditioner(nullptr);
    vehicle->setAudio(nullptr);
    return this;
}