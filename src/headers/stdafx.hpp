#include <unistd.h>
#include <string.h>
#include <iostream>
#include <chrono>
#include <thread>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#include "../class/class_net.hpp"

//repマクロはfor文を簡略化する
#define rep(i, n) for(int i = 0; i < static_cast<int>(n); i++)
