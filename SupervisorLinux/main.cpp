/*
   File main.cpp

   To init the system

    Felipe Viel <felipe.viel@posgrad.ufsc.br>
    Departamento de Engenharia Eletrica

    Data da criacao: Abril de 2021.
    Data da ultima alteracao: 29 de abril de 2021.

*/


#include <iostream>
#include "ControlSupervisor.cpp"


using namespace std;

int main(){

  ControlSupervisor<uint8_t,int> supervisor; //main object - top
  supervisor.control();
  return 0;
  
}

