#ifndef DATACOMMUNICATIONLINUX_H
#define DATACOMMUNICATIONLINUX_H
/*
   File DataCommunicationLinux.h 

   Header file for class DataCommunicationLinux

   Class is base to create serial communication in differente Linux distrubuting system using termios library

   Felipe Viel <felipe.viel@posgrad.ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2021.
   Data da ultima alteracao: 10 de abril de 2021.

*/


#include <iostream>
#include "DataCommunication.cpp"
#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include "libConfig.h"

using namespace std;

template <class TCont, class TSup>
class DataCommunicationLinux : public DataCommunication<TCont, TSup> {
    private:
        char serialName[11];           // serial port name (e.g. /dev/ttyS0, ...)
        TSup  tty_fd;                   // handle to serial port (fd == -1, error!)
    public:
         
        DataCommunicationLinux(){}
        ~DataCommunicationLinux(){
            close(tty_fd); //guarantee when systen exit close serial port
        }

        //virtual method implemented to Linux
        TSup openSerial(TSup port); 
        void sendData();
        int readData(TCont* id, TCont* y, TCont* mo, TCont* d, TCont* h, TCont* mi, TCont* s, TCont* pm, TCont* eT, TCont* cT);
        void closeSerial();
};

#endif