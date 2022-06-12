#include "headers/stdafx.hpp"
#define FRONT_DOOR_SENSOR 11
#define BACK_DOOR_SENSOR 13

//開ける動作
void open_motor(){
	
}
//閉じる動作
int close_motor(){
return 0;	
}
int main()
{
	// 初期化
	if (gpioInitialise() < 0)
	{
		std::cerr << "pigpio初期化失敗!!: " << std::endl;
	}
	// GPIOの入力設定	
	if (gpioSetMode(FRONT_DOOR_SENSOR, PI_INPUT) != 0)
	{
		std::cerr << "フロントドアの設定失敗!!: "  << std::endl;
	}
	//プルアップする
	if (gpioSetPullUpDown(FRONT_DOOR_SENSOR, PI_PUD_UP) != 0)
	{
		std::cerr << "フロントドアの設定失敗!!: "  << std::endl;
	}
	
	if (gpioSetMode(BACK_DOOR_SENSOR, PI_INPUT) != 0)
	{
		std::cerr << "背面ドアの設定失敗!!: "  << std::endl;
	}
	if (gpioSetPullUpDown(BACK_DOOR_SENSOR, PI_PUD_UP) != 0)
	{
		std::cerr << "背面ドアの設定失敗!!: "  << std::endl;
	}
	
	//メインループ
	while(1){
		//前面ドアのセンサが反応したとき
		if(gpioRead(FRONT_DOOR_SENSOR)==0){
			int flag=0;
			while(flag==2){
				open_motor();
				if(gpioRead(FRONT_DOOR_SENSOR)!=0){
					flag+=1;
				}else{
					flag=0;
				}
				if(gpioRead(BACK_DOOR_SENSOR)!=0){
					flag+=1;
				}else{
					flag=0;
				}
			}
			if(close_motor()==1){
				open_motor();
			}
		}//背面ドアのセンサが反応したとき
		else if(gpioRead(FRONT_DOOR_SENSOR)==0){
			open_motor();
			int flag=0;
			while(flag==2){
				open_motor();
				if(gpioRead(FRONT_DOOR_SENSOR)!=0){
					flag+=1;
				}else{
					flag=0;
				}
				if(gpioRead(BACK_DOOR_SENSOR)!=0){
					flag+=1;
				}else{
					flag=0;
				}
			}
			if(close_motor()==1){
				open_motor();
			}
		}
	}
	// pigpioの終了
	gpioTerminate();
    return 0;
}
