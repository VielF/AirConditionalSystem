#ifndef NODERASPPICO_H
#define NODERASPPICO_H
/*
   File Node.h

   Class Node

   Class Node stores integer values for a linked list.
   
   This file has the Node's interface (header file).

   Eduardo Augusto Bezerra <eduardo.bezerra@ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2006.
   Data da ultima alteracao: 6 de abril de 2021.
   Modificado por: Felipe Viel

*/

#include <iostream>

using namespace std;

class NodeRaspPico {

    uint8_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t min;
    uint8_t seg;
    uint8_t pm;
    uint8_t eventType;
    uint8_t configType;
    NodeRaspPico* next;

  public:
    //uint8_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t min, uint8_t seg, uint8_t pm, uint8_t eventType, uint8_t configType, Node* nxt    
    NodeRaspPico(uint8_t y, uint8_t mo, uint8_t d, uint8_t h, uint8_t mi, uint8_t s, uint8_t pm, uint8_t eT, uint8_t cT, NodeRaspPico* nxt);
    int getVal(uint8_t* y, uint8_t* mo, uint8_t* d, uint8_t* h, uint8_t* mi, uint8_t* s, uint8_t* newPm, uint8_t* eT, uint8_t* cT);
    NodeRaspPico* getNext();
    void setVal(uint8_t y, uint8_t mo, uint8_t d, uint8_t h, uint8_t mi, uint8_t s, uint8_t pm, uint8_t eT, uint8_t cT);
    void setNext(NodeRaspPico* nxt);
};

#endif