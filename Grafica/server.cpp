#include "server.h"

Server::Server()     {

    WSAStartup(MAKEWORD(2,0), &WSAData);
    server = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_addr.s_addr = inet_addr("10.0.0.9");
    addr.sin_family=AF_INET;
    addr.sin_port = htons(5555);

    connect(server, (SOCKADDR *)&addr, sizeof(addr));
    cout << "Connected to server!" << endl;
 //   *log = *log + (string)"\n" + "Connected to server!";
}
void Server::Enviar(string mensaje)
{
    for(int i = 0; i<=(int)mensaje.length();i++){
        this->buffer[i]=mensaje[i];
    }

    send(server, buffer, sizeof(buffer), 0);
    cout << "Mensaje enviado!" << endl;
 //   *log = *log + (string)"\n" +  "Mensaje enviado!";
    memset(buffer, 0, sizeof(buffer));
}
string Server::Recibir()
{
    recv(server, buffer, sizeof(buffer), 0);
    cout << "El Servidor dice: " << buffer << endl;
  //  *log =*log + (string)"\n" +  "Mensaje Recibido ";
    string buf=buffer;
    memset(buffer, 0, sizeof(buffer));
    return buf;
}
void Server::CerrarSocket()
{
    closesocket(server);
    WSACleanup();
    cout << "Socket cerrado." << endl << endl;
}

