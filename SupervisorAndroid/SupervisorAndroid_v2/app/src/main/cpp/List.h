#ifndef LISTRASPPICO_H
#define LISTRASPPICO_H
/*
   File List.h

   Header file for class list

   Class List stores Nodes (class Node) in a linked list.
   
   This file has the List's interface (header file).

   Class list is definition for a linked list, having the following operations:

   1. Initialize the list to an empty list.
   2. Free the nodes of a list.
   3. Determine whether a list is empty.
   4. (NOT YET!) Add a node with a given value into the list following
      the first node with another given value.
   5. Add a node with a given value to the front of the list.
   6. Add a node with a given value to the end of the list.
   7. Delete the first node from the list.

   Eduardo Augusto Bezerra <eduardo.bezerra@ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2006.
   Data da ultima alteracao: 6 de abril de 2021.
   Modificado por: Felipe Viel
*/

//#include <iostream>
#include "Node.cpp"



class List {

  Node* head;

public:
  List();
  ~List();
  void insertAfterLast(unsigned char id,unsigned char y, unsigned char mo, unsigned char d, unsigned char h, unsigned char mi, unsigned char s, unsigned char pm, unsigned char eT, unsigned char cT);
  int readFirst(unsigned char* id, unsigned char* y, unsigned char* mo, unsigned char* d, unsigned char* h, unsigned char* mi, unsigned char* s, unsigned char* pm, unsigned char* eT, unsigned char* cT);
  int removeFirst();
  void readPosition(int pos,unsigned char* id, unsigned char* y, unsigned char* mo, unsigned char* d, unsigned char* h, unsigned char* mi, unsigned char* s, unsigned char* pm, unsigned char* eT, unsigned char* cT);
  void listAll();
};

#endif