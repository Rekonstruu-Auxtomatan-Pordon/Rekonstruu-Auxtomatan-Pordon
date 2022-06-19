#pragma once
#include "gpio_control.hpp"

class sensor:public GPIO_control{
    public:
        // センサの初期設定
        void setup(int PIN,int FLAG,std::string error);
    private:
};
