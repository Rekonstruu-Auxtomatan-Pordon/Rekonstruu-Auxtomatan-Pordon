#include <unistd.h>
#include <string.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <pigpio.h>

#include "../class/gpio_control.hpp"

//repマクロはfor文を簡略化する
#define rep(i, n) for(int i = 0; i < static_cast<int>(n); i++)
