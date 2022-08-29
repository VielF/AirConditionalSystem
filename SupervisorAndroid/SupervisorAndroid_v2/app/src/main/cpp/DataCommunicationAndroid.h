#ifndef DATACOMMUNICATIONLINUX_H
#define DATACOMMUNICATIONLINUX_H
/*
   File DataCommunicationAndroid.h

   Header file for class DataCommunicationLinux

   Class is base to create serial communication in differente Android Operating System

   Felipe Viel <felipe.viel@posgrad.ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2021.
   Data da ultima alteracao: 10 de abril de 2021.

*/


//#include <iostream>
#include "DataCommunication.cpp"
#include "libConfig.h"




class DataCommunicationAndroid : public DataCommunication {
    private:
        char serialName[11];           // serial port name (e.g. /dev/ttyS0, ...)
        int  tty_fd;                   // handle to serial port (fd == -1, error!)
    public:

        DataCommunicationAndroid(){}
        ~DataCommunicationAndroid(){}
        int openSerial(int port);
        int sendData();
        int readData(unsigned char* id, unsigned char* y, unsigned char* mo, unsigned char* d, unsigned char* h, unsigned char* mi, unsigned char* s, unsigned char* pm, unsigned char* eT, unsigned char* cT);
        int closeSerial();
};

#endif