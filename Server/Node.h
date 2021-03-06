//
// Created by Jafet on 19/04/2022.
//

#include <string>
#include <algorithm>
#include <functional>
#ifndef PRUEBACLIENTE_NODE_H
#define PRUEBACLIENTE_NODE_H
using namespace std;


template <class T>
class Node {

private:
    Node* Next;
    Node* Down;
    T data;

public:

    Node()
    {
        this->Next = NULL;
        this->Down = NULL;
    }

    Node(T data)
    {   this->Next = NULL;
        this->Down = NULL;
        this->data = data;
    }

    void setData(T data)
    {
        this->data = data;
    }

    T getData()
    {
        return data;
    }

    Node* getNext()
    {
        if(this->Next == NULL){
            this->Next = new Node();
        }
        return this->Next;
    }

    Node* getDown()
    {
        if(this->Down == NULL){
            this->Down = new Node();
        }
        return this->Down;
    }

};

#endif



 //PRUEBACLIENTE_NODE_H

