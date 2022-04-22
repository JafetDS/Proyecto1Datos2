#include <iostream>
#include "Matriz.h"
#include "Server.h"
#include "Game.h"
#include <string>
// Server side C/C++ program to demonstrate Socket
// programming
using namespace  std;
#define PORT 8080



int main() {
    std::cout << "Hello, World!" << std::endl;
   // Matriz<int> matriz;
  //  matriz.setData(0,1,3);
 //   cout<<matriz.getData(0,1)<<endl;
    //Server server;
    Game game;

    game.Start();


    return 0;
}
