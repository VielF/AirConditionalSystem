#ifndef DATACOMMUNICATION_CPP
#define DATACOMMUNICATION_CPP
/*
   File DataCommunication.cpp 

   Im file for class DataCommunication

   This file has the implementation for class DataCommunication

   Felipe Viel <felipe.viel@posgrad.ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2021.
   Data da ultima alteracao: 10 de abril de 2021.

*/


#include <iostream>
#include "DataCommunication.h"


using namespace std;

//function to be used to set generic parameters
template <class TCont, class TSup>
void DataCommunication<TCont, TSup>::setCommuParam(TSup baud, TSup parity, TSup stop){
    baudRate = baud;
    pararityBits = parity;
    stopBits = stopBits;
}

//function to be used to get generic parameters
template <class TCont, class TSup>
void DataCommunication<TCont, TSup>::getCommuParam(TSup* baud, TSup* parity, TSup* stop){
    *baud = baudRate;
    *parity = pararityBits;
    *stop = stopBits;
}

#endif