#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <chrono>
#include <thread>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

const int CLIENTPORT=49500;
const int SERVERPORT=49501;
const int SIZE=4096;

int main()
{
    while (1)
    {
        //ソケットアドレス構造体
        struct sockaddr_in serveraddr;
        struct sockaddr_in clientaddr;
        struct sockaddr_in from_addr;

        int len = sizeof(from_addr);

        //受信バッファ
        char buf[SIZE] = {0};
        char state[SIZE] = {0}; //現在の状態

        int serversock = socket(AF_INET, SOCK_DGRAM, 0);
        int clientsock = socket(AF_INET, SOCK_DGRAM, 0);
        // IPV4を利用する
        serveraddr.sin_family = AF_INET;
        //ポートを設定する
        serveraddr.sin_port = htons(SERVERPORT);
        //宛先IPアドレスの設定
        serveraddr.sin_addr.s_addr = INADDR_ANY;

        // IPV4を利用する
        clientaddr.sin_family = AF_INET;
        //ポートを設定する
        clientaddr.sin_port = htons(CLIENTPORT);
        //送信元IPアドレス
        clientaddr.sin_addr.s_addr = INADDR_ANY;

        if(bind(clientsock, (struct sockaddr *)&clientaddr, sizeof(clientaddr))==-1){
            std::cerr<<"Bind失敗"<<std::endl;
        }

        //データーを受信して、バッファを格納する
        recvfrom(clientsock, buf, sizeof(buf), 0, (struct sockaddr *)&from_addr, (socklen_t *)&len);
        if (strcmp(buf, "exit") == 0)
        {
            close(clientsock);
            break;
        }
        //受信したデータを表示する
        std::cout<<"受信したデータは"<<buf<<"IPアドレスは"<<std::endl<<inet_ntoa(from_addr.sin_addr)<<std::endl;
        serveraddr.sin_addr.s_addr = from_addr.sin_addr.s_addr;
        if(bind(serversock, (struct sockaddr *)&serveraddr, sizeof(serveraddr))==-1){
            std::cerr<<"Bind失敗"<<std::endl;
        }

        strcpy(state, buf);
        for (int i = 0; i < 10; i++)
        {
            sendto(serversock, state, sizeof(state), 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
            std::chrono::milliseconds(500);
        }
        //ソケットを閉じる(呼出す必要!)*/
        close(clientsock);
        close(serversock);
    }
    return 0;
}
