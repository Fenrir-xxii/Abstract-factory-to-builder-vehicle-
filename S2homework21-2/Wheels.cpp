#include "Wheels.h"

std::string StandardWheels::getName()
{
	return "Standard wheels";
}

int StandardWheels::getMaxSpeed()
{
	return 100;
};

std::string SpeedWheels::getName()
{
	return "Speed wheels";
}

int SpeedWheels::getMaxSpeed()
{
	return 200;
};