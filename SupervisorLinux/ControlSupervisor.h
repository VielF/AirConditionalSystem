#ifndef CONTROLSUPERVISOR_H
#define CONTROLSUPERVISOR_H
/*
   File ControlSupervisor.h 

   Header file for class ControlSupervisor

   Class is base to logic control of supervisor 

   Felipe Viel <felipe.viel@posgrad.ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2021.
   Data da ultima alteracao: 29 de abril de 2021.

*/


#include <iostream>
#include "DataCommunicationLinux.cpp"
#include "ProcessingDataList.cpp"

using namespace std;

template <class TCont, class TSup>
class ControlSupervisor{
    private:
        DataCommunicationLinux<TCont,TSup> serialCom; //object to communication on Linux OS         
        ProcessingDataList<TCont,TSup> dataProcessing; //object to print events by some opertation type
        stateControlSupervisor state;  //to control state of control method
    public:
         
        ControlSupervisor(): state(stInit){}  //contructor 
        void control(); //FSM to control system
        void readData();  //read events from control
        void displayData(); //to display events by some opertation type
};

#endif