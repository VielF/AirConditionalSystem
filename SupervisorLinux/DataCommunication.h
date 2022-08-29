#ifndef DATACOMMUNICATION_H
#define DATACOMMUNICATION_H

/*
   File DataCommunication.h 

   Header file for class DataCommunication

   Class is base to create serial communication in differente OSs

   Felipe Viel <felipe.viel@posgrad.ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2021.
   Data da ultima alteracao: 10 de abril de 2021.

*/


#include <iostream>
#include "List.cpp"


using namespace std;

template <class TCont, class TSup>
class DataCommunication {
    protected:
        TSup baudRate;
        TSup stopBits;
        TSup pararityBits;

    public:
         
        DataCommunication():baudRate(0),stopBits(0),pararityBits(0) {}
        void setCommuParam(TSup baud, TSup parity, TSup stop);
        void getCommuParam(TSup* baud, TSup* parity, TSup* stop);

        //methods to be implemented in OS or platform using their resources
        virtual TSup openSerial(TSup port) = 0;  
        virtual void sendData() = 0;
        virtual int readData(TCont* id, TCont* y, TCont* mo, TCont* d, TCont* h, TCont* mi, TCont* s, TCont* pm, TCont* eT, TCont* cT) = 0;
        virtual void closeSerial() = 0;
};

#endif