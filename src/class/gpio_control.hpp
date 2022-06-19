#pragma once
#include "../headers/stdafx.hpp"

class GPIO_control{
    public:
        // GPIO_controlクラスのコンストラクタ
        // (PIN番号,GPIOの入力か出力のFlag,エラー名)
        GPIO_control(int PIN,int FLAG,std::string error);
    private:
};
