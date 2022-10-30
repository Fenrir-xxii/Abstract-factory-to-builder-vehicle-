#include "Car.h"

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
