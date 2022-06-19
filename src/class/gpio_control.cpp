#pragma once
#include "../headers/stdafx.hpp"
#include "gpio_control.hpp"

GPIO_control::GPIO_control(int PIN,int FLAG,std::string error){
    //GPIO の入力設定
    if (gpioSetMode(PIN, FLAG) != 0)
	  {
		    std::cout <<error << std::endl;
	  }
}
