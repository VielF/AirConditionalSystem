#ifndef LISTRASPPICO_CPP
#define LISTRASPPICO_CPP

/*
   File List.cpp

   Class List stores Nodes (class Node) in a linked list.
   
   This file has the implementation for class List

   Class list is definition for a linked list, having the following operations:

   1. Initialize the list to an empty list.
   2. Free the nodes of a list.
   3. Determine whether a list is empty.
   6. Add a node with a given value to the end of the list.
   7. Delete the first node from the list.

   Eduardo Augusto Bezerra <eduardo.bezerra@ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2006.
   Data da ultima alteracao: 6 de abril de 2021.
   Modificado por: Felipe Viel

*/

#include <iostream>

#include "ListRaspPico.h"

using namespace std;

ListRaspPico::ListRaspPico() {
   head = 0;
}

ListRaspPico::~ListRaspPico() {
  NodeRaspPico* cursor = head;
  while(head) {
    cursor = cursor->getNext();
    delete head;
    head = cursor;
  }
  head = 0; // Officially empty
}


void ListRaspPico::insertAfterLast(uint8_t y, uint8_t mo, uint8_t d, uint8_t h, uint8_t mi, uint8_t s, uint8_t pm, uint8_t eT, uint8_t cT) {
  NodeRaspPico* p = head;
  NodeRaspPico* q = head;

  if (head == 0)
     head = new NodeRaspPico(y,mo,d,h,mi,s,pm,eT, cT, head);
  else {
     while (q != 0) {
        p = q;
        q = p->getNext();
     }
     p->setNext(new NodeRaspPico(y,mo,d,h,mi,s,pm,eT, cT,0));
  }
}

int ListRaspPico::readFirst(uint8_t* y, uint8_t* mo, uint8_t* d, uint8_t* h, uint8_t* mi, uint8_t* s, uint8_t* pm, uint8_t* eT, uint8_t* cT) {
   //head->getVal(&y, &mo, &d, &h, &mi, &s, &pm, &eT, &cT); 
   head->getVal(y, mo, d, h, mi, s, pm, eT, cT); 
   return 0;
}

int ListRaspPico::removeFirst() {
  int retval = 0;
  if (head != 0){
     //cout << "Removendo: " << head << endl;
     //cout << "e fica:" << head->getVal() << endl;
     //retval = head->getVal();
     NodeRaspPico* oldHead = head;
     head = head->getNext();
     delete oldHead;
  }
  return 0;
}

/*
void ListRaspPico::listAll() {
  NodeRaspPico* aux = head;
  while (aux != 0){
     cout << aux->getVal() << endl;
     aux = aux->getNext();
  }
}
*/

#endif