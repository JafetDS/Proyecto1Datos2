//
// Created by Jafet on 21/04/2022.
//

#include "Game.h"

Game::Game() {



}

void Game::Start(){
   // srand (time(NULL));
    Pcard = 12;
    player1 = 0;
    player2 = 0;
    server.Start();
    string mensaje;
    cout<<"Ingrese juagdor 1"<<endl;
    mensaje = server.Recibir();
    cin>>Nameplayer1;
    cout<<"Ingrese juagdor 2"<<endl;
    mensaje = server.Recibir();
    cin>>Nameplayer2;
/**
    turn = rand()%(2);
    if (turn = 0){
        Cplayer = &player1;
        cout<<"Turno "+ Nameplayer1<<endl;
    }else{
        Cplayer = &player2;
        cout<<"Turno "+ Nameplayer2<<endl;
    }
*/
    Create_game();

    turn = 0;
    cout<<"Turno "+ Nameplayer1<<endl;
    Cplayer = &player1;
    while(checkWin()){
        cout<<*Cplayer<<endl;

        int a,b,c,d;
        cout<<"selec first card"<<endl;
        mensaje = server.Recibir();
        cin>>a;
        mensaje = server.Recibir();
        cin>>b;
        server.Enviar(imgconv(Memo.getImage(matriz.getData(a,b))))
        cout<<"selec second card"<<endl;
        mensaje = server.Recibir();
        cin>>c;
        mensaje = server.Recibir();
        cin>>d;



        server.Enviar(imgconv(Memo.getImage(matriz.getData(c,d))))
        this->Selec(a,b,c,d);
        print();

    }

    cout<<checkWinner()<<endl;






}

void Game::Create_game(){
    int data = 0;
    for(int p = 0; p<12 ; p+=2){
        this->memory.setData(0,p,data);
        this->memory.setData(0,p+1,data);
        data = data + 1;
    }
    cout<<endl;
    for(int k = 0 ; k<12 ; k++){
        cout<<this->memory.getData(0,k);
    }
    cout<<endl;
    int Idata = 0;
    for(int i = 0 ; i<3 ; i++){
        for (int j = 0 ; j< 4 ;j++){
            matriz.setData(i,j,this->memory.getData(0,Idata));
            Idata = Idata+1;
        }
    }

    print();
    Swap();
    print();
}
void Game::set_Players(string name1,string name2) {
    this->Nameplayer1 = name1;
    this->Nameplayer2 = name2;
}


void Game::print(){
    for(int i = 0 ; i<3 ; i++){
        for (int j = 0 ; j< 4 ;j++){
            cout<<this->matriz.getData(i,j);
        }
        cout<<endl;
    }
    cout<<endl;

}

void Game::Send_image() {

}
void Game::Swap(){
    // rand()%(range);
    srand (time(NULL));
    for(int i = 0; i<9; i++){
        int a = rand()%(3);
        int b = rand()%(4);
        int c = rand()%(3);
        int d = rand()%(4);

        int var = this->matriz.getData(a,b);
        this->matriz.setData(a,b,this->matriz.getData(c,d));
        this->matriz.setData(c,d,var);

    }

}
void Game::Player_Points(int n){
    *Cplayer = *Cplayer+n;
    if (turn == 0){
        turn = 1;
        Cplayer = &player2;
        cout<<"Turno "+ Nameplayer2<<endl;
    }else{
        turn = 0;
        Cplayer = &player1;
        cout<<"Turno "+ Nameplayer1<<endl;
    }
    if (n>0){
        Pcard = Pcard-2;
    }
}

bool Game::Selec(int a, int b, int c, int d){
    if(this->matriz.getData(a,b) == this->matriz.getData(c,d)){
        this->matriz.setData(a,b,-1);
        this->matriz.setData(c,d,-1);
        Player_Points(100);
        return true;
    }else{
        Player_Points(-10);
        return false;
    }
}

bool Game::checkWin(){
    if (Pcard == 0){
        return false;
    }else{
        return true;
    }
}

string Game::checkWinner(){
    if (player1>player2){
        return Nameplayer1;
    }else{
        return Nameplayer2;
    }
}

void Game::imgconv(Image image){

}