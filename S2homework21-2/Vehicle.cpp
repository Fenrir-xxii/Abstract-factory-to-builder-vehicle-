#include "Vehicle.h"

void Vehicle::drive()
{
    int speed = engine->getSpeed(*fuel);
    if (speed > wheels->getMaxSpeed()) {
        throw "WHEELS FELL OFF";
    }
}

void Vehicle::info()
{
    system("cls");
    std::cout << "Vehicle type: " << this->name << std::endl;
    engine->info();
    std::cout << "Fuel: ";
    fuel->info();
    wheels->info();
    std::cout << qtyOfWheels << " wheels." << std::endl;
}
