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


//#include <iostream>
#include "DataCommunication.h"





void DataCommunication::setCommuParam(int baud, int parity, int stop){
    baudRate = baud;
    pararityBits = parity;
    stopBits = stop;
}


void DataCommunication::getCommuParam(int* baud, int* parity, int* stop){
    *baud = baudRate;
    *parity = pararityBits;
    *stop = stopBits;
}

#endif