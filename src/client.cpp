#include "headers/stdafx.h"
//repマクロはfor文を簡略化する
#define rep(i, n) for(int i = 0; i < static_cast<int>(n); i++)

const int CLIENTPORT=49500;
const int SERVERPORT=49501;
const int SIZE=4096;

int main()
{
    while (1)
    {
        int clientsock;
        int serversock;
        
        //ソケットアドレス構造体
        struct sockaddr_in from_addr;
        
        class_net client;
        class_net server;

        int len = sizeof(from_addr);

        //受信バッファ
        char buf[SIZE] = {0};
        char state[SIZE] = {0}; //現在の状態
        
        clientsock=client.create(CLIENTPORT);
        serversock=server.create(SERVERPORT);

        //データーを受信して、バッファを格納する
        recvfrom(clientsock, buf, sizeof(buf), 0, reinterpret_cast<struct sockaddr *>(&from_addr), reinterpret_cast<socklen_t *>(&len));
        if (strcmp(buf, "exit") == 0)
        {
            close(clientsock);
            break;
        }
        //受信したデータを表示する
        std::cout<<"受信したデータは"<<buf<<std::endl<<"IPアドレスは"<<inet_ntoa(from_addr.sin_addr)<<std::endl;
        server.socket_address.sin_addr.s_addr = from_addr.sin_addr.s_addr;
        strcpy(state, buf);
        rep(i,10){
            sendto(serversock, state, sizeof(state), 0, reinterpret_cast<struct sockaddr *>(&server.socket_address), sizeof(server.socket_address));
            std::chrono::milliseconds(500);
        }
        //ソケットを閉じる(呼出す必要!)*/
        close(clientsock);
        close(serversock);
    }
    return 0;
}
