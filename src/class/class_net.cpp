#include "class_net.h"

int class_net::create(int PORT){
    int created_socket=socket(AF_INET, SOCK_DGRAM, 0);
    // IPV4を利用する
    socket_address.sin_family = AF_INET;
    //ポートを設定する
    socket_address.sin_port = htons(PORT);
    //宛先IPアドレスの設定
    socket_address.sin_addr.s_addr = INADDR_ANY;
    if(bind(created_socket, (struct sockaddr *)&socket_address, sizeof(socket_address))==-1){
            std::cerr<<"Bind失敗 at create"<<std::endl;
    }
    return  created_socket;
}

void class_net::update(int socket){
    if(bind(socket, (struct sockaddr *)&socket_address, sizeof(socket_address))==-1){
            perror("bind");
        }
}
