//
// Created by Jafet on 17/04/2022.
//

#ifndef PRUEBACLIENTE_SERVER_H
#define PRUEBACLIENTE_SERVER_H

#include <iostream>
#include <string>
#include <winsock2.h>
#include <sstream>
using namespace std;


class Server {

public:
    Server();
    WSADATA WSAData;
    SOCKET server, client;
    SOCKADDR_IN serverAddr, clientAddr;
    char buffer[1024];

    string Recibir();
    void Enviar(string);
    void CerrarSocket();
    void Start();

};


#endif //PRUEBACLIENTE_SERVER_H
