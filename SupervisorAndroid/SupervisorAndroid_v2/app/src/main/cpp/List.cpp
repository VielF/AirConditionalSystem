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

//#include <iostream>


#include "List.h"



List::List() {
   head = 0;
}

List::~List() {
  Node* cursor = head;
  while(head) {
    cursor = cursor->getNext();
    delete head;
    head = cursor;
  }
  head = 0; // Officially empty
}


void List::insertAfterLast(unsigned char id,unsigned char y, unsigned char mo, unsigned char d, unsigned char h, unsigned char mi, unsigned char s, unsigned char pm, unsigned char eT, unsigned char cT) {
  Node* p = head;
  Node* q = head;

  if (head == 0)
     head = new Node(id,y,mo,d,h,mi,s,pm,eT, cT, head);
  else {
     while (q != 0) {
        p = q;
        q = p->getNext();
     }
     p->setNext(new Node(id,y,mo,d,h,mi,s,pm,eT, cT,0));
  }
}

int List::readFirst(unsigned char* id, unsigned char* y, unsigned char* mo, unsigned char* d, unsigned char* h, unsigned char* mi, unsigned char* s, unsigned char* pm, unsigned char* eT, unsigned char* cT) {
   //head->getVal(&y, &mo, &d, &h, &mi, &s, &pm, &eT, &cT); 
   head->getVal(id,y, mo, d, h, mi, s, pm, eT, cT); 
   return 0;
}

int List::removeFirst() {
  int retval = 0;
  if (head != 0){
     //cout << "Removendo: " << head << endl;
     //cout << "e fica:" << head->getVal() << endl;
     //retval = head->getVal();
     Node* oldHead = head;
     head = head->getNext();
     delete oldHead;
  }
  return 0;
}


void List::readPosition(int pos, unsigned char* id, unsigned char* y, unsigned char* mo, unsigned char* d, unsigned char* h, unsigned char* mi, unsigned char* s, unsigned char* pm, unsigned char* eT, unsigned char* cT){
   Node* aux = head;
   int count = 0;
   if(pos == 0 && aux != 0){
      aux->getVal(id,y, mo, d, h, mi, s, pm, eT, cT);
   }else{
      while(count < pos && aux != 0){
         aux = aux->getNext();
         count++;
         aux->getVal(id,y, mo, d, h, mi, s, pm, eT, cT);
      }
      
   }
}

void List::listAll() {
    unsigned char id;
    unsigned char y;
    unsigned char mo;
    unsigned char d;
    unsigned char h;
    unsigned char mi;
    unsigned char s;
    unsigned char pm;
    unsigned char eT;
    unsigned char cT;
    Node* aux = head;
    while (aux != 0){
        aux->getVal(&id,&y, &mo, &d, &h, &mi, &s, &pm, &eT, &cT);
        //printf("%u-%u-%u-%u-%u-%u-%u-%u-%u-%u\n", id,y,mo,d,h,mi,s,pm,eT,cT);
        aux = aux->getNext();
    }
}

#endif