#pragma once
#include "sensor.hpp"

void sensor::setup(int PIN,int FLAG,std::string error){
	if (gpioSetPullUpDown(PIN,FLAG) != 0)
	{
		std::cerr <<error<< std::endl;
	}
}
