/*
   File main.cpp

   Test program for Node and List classes.

   Eduardo Augusto Bezerra <eduardo.bezerra@ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2006.
   Data da ultima alteracao: 8 de outubro de 2015.

*/

#include "List.cpp"

int main(){

  List lista1,lista2;
  int saida;
  
  lista1.insertBeforeFirst(5);
  lista1.insertAfterLast(10);
  
  cout << "Primeiro nodo contem: " << lista1.readFirst() << endl;
  
  lista1.insertionSort(4);
  
  lista1.listAll();
  
  cout << "Digite F para finalizar o programa" << endl;
  
  cin >> saida;
  
  return 0;
  
}

