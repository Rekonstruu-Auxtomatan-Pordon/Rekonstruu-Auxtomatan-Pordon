#include "headers/stdafx.hpp"

const int FRONT_DOOR_SENSOR 11
const int BACK_DOOR_SENSOR 13

int main()
{
	// 初期化
	if (gpioInitialise() < 0)
	{
		std::cerr << "pigpio初期化失敗!!: " << e.what() << std::endl;
	}
	// GPIOの入力設定	
	if (gpioSetMode(FRONT_DOOR_SENSOR, PI_INPUT) != 0)
	{
		std::cerr << "フロントドアの設定失敗!!: " << e.what() << std::endl;
	}
	if (gpioSetMode(BACK_DOOR_SENSOR, PI_INPUT) != 0)
	{
		std::cerr << "背面ドアの設定失敗!!: " << e.what() << std::endl;
	}
	//メインループ
	while(1){
		
	}
	// pigpioの終了
	gpioTerminate();
    return 0;
}
