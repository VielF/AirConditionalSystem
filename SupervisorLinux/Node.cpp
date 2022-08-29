#ifndef NODERASPPICO_CPP
#define NODERASPPICO_CPP

/*
   File Node.cpp

   Class Node

   Class Node stores integer values for a linked list.
   
   This file has the implementation for the Node's interface.

   Eduardo Augusto Bezerra <eduardo.bezerra@ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2006.
   Data da ultima alteracao: 6 de abril de 2021.
   Modificado por: Felipe Viel
*/
#include <iostream>

#include "libConfig.h"

#include "Node.h"

using namespace std;

// Constructor - initializes the node
//
Node::Node(uint8_t id,uint8_t y, uint8_t mo, uint8_t d, uint8_t h, uint8_t mi, uint8_t s, uint8_t pm, uint8_t eT, uint8_t cT, Node* nxt){
    idController = id;
    year = y;
    month = mo;
    day = d;
    hour = h;
    min = mi;
    seg = s;
    pm = pm;
    eventType = eT; 
    configType = cT;
    next = nxt;
}

// getVal returns the integer value stored in the node
//
int Node::getVal(uint8_t* id, uint8_t* y, uint8_t* mo, uint8_t* d, uint8_t* h, uint8_t* mi, uint8_t* s, uint8_t* newPm, uint8_t* eT,uint8_t* cT){
    *id = idController;
    *y = year;
    *mo = month;
    *d = day;
    *h = hour;
    *mi = min;
    *s = seg;
    *newPm = pm;
    *eT = eventType; 
    *cT = configType;
    return 0;
}

// getNext returns a pointer for the next node in the linked list
//
Node* Node::getNext(){
     return next;
}

// setVal stores the integer value in the node
//
void Node::setVal(uint8_t id, uint8_t y, uint8_t mo, uint8_t d, uint8_t h, uint8_t mi, uint8_t s, uint8_t pm, uint8_t eT,uint8_t cT){
    idController = id;
    year = y;
    month = mo;
    day = d;
    hour = h;
    min = mi;
    seg = s;
    pm = pm;
    eventType = eT; 
    configType = cT;
}

// setNext stores the pointer to the next node in the list in the "next" field
//
void Node::setNext(Node* nxt){
    next = nxt;
}

#endif