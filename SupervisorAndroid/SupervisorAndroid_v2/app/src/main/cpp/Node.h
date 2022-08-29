#ifndef NODE_H
#define NODE_H
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

//#include <iostream>



class Node {
    unsigned char idController;
    unsigned char year;
    unsigned char month;
    unsigned char day;
    unsigned char hour;
    unsigned char min;
    unsigned char seg;
    unsigned char pm;
    unsigned char eventType;
    unsigned char configType;
    Node* next;

  public:
    //uint8_t idController, uint8_t year, uint8_t month, uint8_t day, 
    //      uint8_t hour, uint8_t min, uint8_t seg, uint8_t pm, uint8_t eventType, uint8_t configType, Node* nxt    
    Node(unsigned char id, unsigned char y, unsigned char mo, unsigned char d, unsigned char h, unsigned char mi, unsigned char s, unsigned char pm, unsigned char eT, unsigned char cT, Node* nxt);
    int getVal(unsigned char* id,unsigned char* y, unsigned char* mo, unsigned char* d, unsigned char* h, unsigned char* mi, unsigned char* s, unsigned char* newPm, unsigned char* eT, unsigned char* cT);
    Node* getNext();
    void setVal(unsigned char id,unsigned char y, unsigned char mo, unsigned char d, unsigned char h, unsigned char mi, unsigned char s, unsigned char pm, unsigned char eT, unsigned char cT);
    void setNext(Node* nxt);
};

#endif