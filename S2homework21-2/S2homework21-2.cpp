#include <iostream>
#include "Car.h"


void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void clientCode(CarPartsFactory* factory)
{
    try {
        Car car(factory->createEngine(),
            factory->createWheels(),
            factory->createFuel(100));
        system("cls");
        car.info();
        car.drive();
        std::cout << "All OK" << std::endl << std::endl;
        system("pause");
        system("cls");
    }
    catch (const char* e) {
        std::cout << "Error" << std::endl;
        std::cout << e << std::endl;
    }
    delete factory;
};

int main()
{
    ShowConsoleCursor(false);

    Menu menu({ "Gasoline car", "Diesel car", "Electric car", "Hybrid car" });
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
            CarPartsFactory* factory;
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

