#ifndef CONTROLSUPERVISOR_H
#define CONTROLSUPERVISOR_H
/*
   File ControlSupervisor.h 

   Header file for class ControlSupervisor

   Class is base to logic control of supervisor 

   Felipe Viel <felipe.viel@posgrad.ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2021.
   Data da ultima alteracao: 10 de abril de 2021.

*/


//#include <iostream>
#include "DataCommunicationAndroid.h"
#include "ProcessingDataList.cpp"
#include <string>



class ControlSupervisor{
    private:
        DataCommunicationAndroid serialCom;
        ProcessingDataList dataProcessing;
        stateControlSupervisor state;
    public:
         
        ControlSupervisor(): state(stInit){}
        std::string readData();
        std::string displayData(int optionDisplay, int start, int end, int month, int monthNumber);
};

#endif