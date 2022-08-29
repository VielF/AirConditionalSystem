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


//#include <iostream>
#include "List.cpp"





class DataCommunication {
    protected:
        int baudRate;
        int stopBits;
        int pararityBits;

    public:
         
        DataCommunication():baudRate(0),stopBits(0),pararityBits(0) {}
        void setCommuParam(int baud, int parity, int stop);
        void getCommuParam(int* baud, int* parity, int* stop);
        virtual int openSerial(int port) = 0;
        virtual int sendData() = 0;
        virtual int readData(unsigned char* id, unsigned char* y, unsigned char* mo, unsigned char* d, unsigned char* h, unsigned char* mi, unsigned char* s, unsigned char* pm, unsigned char* eT, unsigned char* cT) = 0;
        virtual int closeSerial() = 0;
};

#endif