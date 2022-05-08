#pragma once
#include "../headers/stdafx.hpp"

class class_net{
    public:
        struct sockaddr_in socket_address;
        //ソケットの作成
        int create(int PORT);
        void update(int socket);
        void send(int socket);
    private:
};
