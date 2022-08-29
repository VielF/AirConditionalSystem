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
//#include <iostream>

#include "libConfig.h"

#include "Node.h"


// Constructor - initializes the node
//
Node::Node(unsigned char id,unsigned char y, unsigned char mo, unsigned char d, unsigned char h, unsigned char mi, unsigned char s, unsigned char pm, unsigned char eT, unsigned char cT, Node* nxt){
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
int Node::getVal(unsigned char* id, unsigned char* y, unsigned char* mo, unsigned char* d, unsigned char* h, unsigned char* mi, unsigned char* s, unsigned char* newPm, unsigned char* eT,unsigned char* cT){
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
void Node::setVal(unsigned char id, unsigned char y, unsigned char mo, unsigned char d, unsigned char h, unsigned char mi, unsigned char s, unsigned char newPm, unsigned char eT,unsigned char cT){
    idController = id;
    year = y;
    month = mo;
    day = d;
    hour = h;
    min = mi;
    seg = s;
    pm = newPm;
    eventType = eT; 
    configType = cT;
}

// setNext stores the pointer to the next node in the list in the "next" field
//
void Node::setNext(Node* nxt){
    next = nxt;
}

#endif