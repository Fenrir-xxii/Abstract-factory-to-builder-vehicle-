#include <iostream>
#include "Car.h"
#include "Motorbike.h"
#include "Truck.h"


void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void clientCode(VehiclePartsFactory* factory)
{
    try {
        Vehicle vehicle(factory->createEngine(),
            factory->createWheels(),
            factory->createFuel(100),
            factory->getName(),
            factory->getQtyOfWheels());
        system("cls");
        vehicle.info();
        vehicle.drive();
        std::cout << "All OK" << std::endl << std::endl;
        system("pause");
        system("cls");
    }
    catch (const char* e) {
        std::cout << "Error" << std::endl;
        std::cout << e << std::endl;
        system("pause");
        system("cls");
    }
    delete factory;
};

int main()
{
    ShowConsoleCursor(false);

    Menu menu({ "Gasoline car", "Diesel car", "Electric car", "Hybrid car", "Gasoline motorbike", "Diesel motorbike" , "Electric motorbike", "Diesel truck" });
    int key = -1;
    int selection = -1;
    int userChoice = -1;

    while (key != ESC)
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
            userChoice = menu.getSelectedOption();
            VehiclePartsFactory* factory;
            try {
                switch (userChoice) {
                case 0:
                    factory = new GasolineCarPartsFactory();
                    system("cls");
                    break;
                case 1:
                    factory = new DieselCarPartsFactory();
                    system("cls");
                    break;
                case 2:
                    factory = new ElectricCarPartsFactory();
                    system("cls");
                    break;
                case 3:
                    factory = new HybridCarPartsFactory();
                    system("cls");
                    break;
                case 4:
                    factory = new GasolineMotorbikePartsFactory();
                    system("cls");
                    break;
                case 5:
                    factory = new DieselMotorbikePartsFactory();
                    system("cls");
                    break;
                case 6:
                    factory = new ElectricMotorbikePartsFactory();
                    system("cls");
                    break;
                case 7:
                    factory = new DieselTruckPartsFactory();
                    system("cls");
                    break;
                default:
                    throw "Not implemented type ";
                }
                clientCode(factory);
            }
            catch (const char* e) {
                std::cout << "Error: " << e << std::to_string(userChoice) << std::endl;
            }
            break;
        case ESC:
            system("cls");
            break;
        default:
            break;
        }
    }

    return 0;
};

