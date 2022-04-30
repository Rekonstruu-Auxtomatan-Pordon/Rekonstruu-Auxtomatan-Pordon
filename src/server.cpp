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
const int SIZE =4096;

const char* DESTIP="127.0.0.1";
const char* SOURCEIP="127.0.0.1";

int main()
{
    std::string welcome = "現在のドアはどの状態ですか?\nstart(ドアを開けます)\nclose(ドアを閉じます\nexit(この無限ループを終了できます)\n";
    while (1)
    {
        //ソケットアドレス構造体
        struct sockaddr_in serveraddr;
        struct sockaddr_in clientaddr;
        struct sockaddr_in from_addr;

        int len = sizeof(from_addr);

        //受信バッファ
        char buf[SIZE];
        char state[SIZE]; //現在の状態

        int serversock = socket(AF_INET, SOCK_DGRAM, 0);
        int clientsock = socket(AF_INET, SOCK_DGRAM, 0);
        // IPV4を利用する
        serveraddr.sin_family = AF_INET;
        //ポートを設定する
        serveraddr.sin_port = htons(CLIENTPORT);
        //宛先IPアドレスの設定
        serveraddr.sin_addr.s_addr = inet_addr(DESTIP);

        // IPV4を利用する
        clientaddr.sin_family = AF_INET;
        //ポートを設定する
        clientaddr.sin_port = htons(SERVERPORT);
        //送信元IPアドレス
        clientaddr.sin_addr.s_addr = INADDR_ANY;
        if(bind(serversock, (struct sockaddr *)&serveraddr, sizeof(serveraddr))==-1){
            std::cerr<<"Bind失敗"<<std::endl;
        }
        if(bind(clientsock, (struct sockaddr *)&clientaddr, sizeof(clientaddr))==-1){
            std::cerr<<"Bind失敗"<<std::endl;
        }

        std::cout << welcome;
        std::cin >> state;
        // exitが入力されたときbreakする
        if (strcmp(state, "exit") == 0)
        {
            sendto(serversock, state, sizeof(state), 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
            //時間待機しないと、ソケットが閉じられるため、その対策
            //!!状況に応じて時間を変更すること!!
            std::chrono::milliseconds(500);
            break;
        }
        // パケットをUDPで送信
        sendto(serversock, state, sizeof(state), 0, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
        for (int i = 0; i < 10; i++)
        {
            recvfrom(clientsock, buf, sizeof(buf), 0, (struct sockaddr *)&from_addr, (socklen_t *)&len);
            std::cout<<buf<<"中..."<<std::endl;
        }
        //ソケットを閉じる
        close(clientsock);
        close(serversock);
    }
    return 0;
}
