#include "Car.h"

void Car::info()
{
    system("cls");
    drawName();
    //std::cout << "Inside car:\n";
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

void Car::drawName()
{
    std::vector<COORD> coordinates({ {1,0} ,{2,0}, {3,0}, {4,0}, {8,0} , {9,0}, {13,0} , {14,0}, {15,0} ,
                                    {1,1}, {7,1}, {10,1}, {13,1}, {16,1},
                                    {1,2}, {7,2}, {10,2}, {13,2}, {16,2},
                                    {1,3}, {7,3}, {8,3}, {9,3}, {10,3}, {13,3}, {14,3}, {15,3},
                                    {1,4}, {2,4}, {3,4}, {4,4}, {7,4}, {10,4}, {13,4}, {16,4} });

    SetColor(BLACK, GREEN_FADE);
    for (int i = 0; i < coordinates.size(); i++)
    {
        SetCursorPosition(coordinates[i]);
        std::cout << ' ';
    }
    SetColor(WHITE, BLACK);
    std::cout << std::endl << std::endl;
}

//FACTORY

std::string CarPartsFactory::getName()
{
    return "Car";
}
int CarPartsFactory::getQtyOfWheels()
{
    return 4;
}

Engine* GasolineCarPartsFactory::createEngine() 
{
    return new StandardGasolineEngine();
}

Fuel* GasolineCarPartsFactory::createFuel(int volume) 
{
    return new Gasoline(volume);
}

Wheels* GasolineCarPartsFactory::createWheels() 
{
    return new StandardWheels();
}

Engine* DieselCarPartsFactory::createEngine() 
{
    return new StandardDieselEngine();
}

Fuel* DieselCarPartsFactory::createFuel(int volume) 
{
    return new Diesel(volume);
}

Wheels* DieselCarPartsFactory::createWheels() 
{
    return new SpeedWheels();
}

Engine* ElectricCarPartsFactory::createEngine()
{
    return new StandardElectricEngine();
}

Fuel* ElectricCarPartsFactory::createFuel(int volume)
{
    return new Electricity(volume);
}

Wheels* ElectricCarPartsFactory::createWheels()
{
    return new StandardWheels();
}

Engine* HybridCarPartsFactory::createEngine()
{
    return new StandardHybridEngine();
}

Fuel* HybridCarPartsFactory::createFuel(int volume)
{
    Menu menu({ "Elecricity", "Gasoline" });
    int key = -1;
    int selection = -1;
    while (true)
    {
        menu.drawFrame();
        menu.drawOptions();
        key = getKey();

        switch (key)
        {
        case UP_ARROW:
            menu.up();
            break;
        case DOWN_ARROW:
            menu.down();
            break;
        case ENTER:
            selection = menu.getSelectedOption();
            switch (selection)
            {
            case 0:
                return new Electricity(volume);
                break;
            case 1:
                return new Gasoline(volume);
                break;
            }
            break;
        }
    }
}

Wheels* HybridCarPartsFactory::createWheels()
{
    return new SpeedWheels();
};

//BUILDER

VehicleBuilder* CarBuilder::start()
{
    delete vehicle;
    vehicle = new Car();
    return this;
}

VehicleBuilder* GasolineCarStandardBuilder::makeRequired() 
{
    vehicle->setEngine(new StandardGasolineEngine());
    vehicle->setFuel(new Gasoline(100));
    vehicle->setWheels(new StandardWheels());
    return this;
}

VehicleBuilder* GasolineCarStandardBuilder::makeOptions() 
{
    vehicle->setAirConditioner(nullptr);
    vehicle->setAudio(nullptr);
    return this;
}

VehicleBuilder* GasolineCarDeluxeBuilder::makeOptions() 
{
    vehicle->setAirConditioner(new TwoZoneClimateControl());
    vehicle->setAudio(new HiFiAudioSystem());
    return this;
}