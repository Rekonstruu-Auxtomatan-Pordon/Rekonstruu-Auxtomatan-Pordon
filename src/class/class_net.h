#pragma once
#include "../headers/headers.h"

class class_net{
    public:
        struct sockaddr_in socket_address;
        //ソケットの作成
        int create(int PORT);
        void update(int socket);
        void send(int socket);
    private:
};
