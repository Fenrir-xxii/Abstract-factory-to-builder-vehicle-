#include "VehicleOptionalParts.h"

// WHEELS

void Wheels::info()
{
	std::cout << getName() << " max speed " << std::to_string(getMaxSpeed()) << std::endl;
}

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

std::string ReinforcedWheels::getName()
{
	return "Reinforced wheels";
}

int ReinforcedWheels::getMaxSpeed()
{
	return 220;
};

// AIR CONDITIONER

void TwoZoneClimateControl::info() 
{
	std::cout << "Two Zone Climate Control and air conditioner" << std::endl;
}

// AUDIO

void HiFiAudioSystem::info() 
{
	std::cout << "HiFi audio system" << std::endl;
}

void MarineAudioSystem::info()
{
	std::cout << "Marine audio system" << std::endl;
}

//PROPELLER

void Propeller::info()
{
	std::cout << this->getName() << " max speed " << std::to_string(getMaxSpeed()) << std::endl;
}

std::string FourBladePropeller::getName()
{
	return "Four-blade propeller";
}

int FourBladePropeller::getMaxSpeed()
{
	return 400;
}