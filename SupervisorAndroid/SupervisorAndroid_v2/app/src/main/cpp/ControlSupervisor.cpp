#ifndef CONTROLSUPERVISOR_CPP
#define CONTROLSUPERVISOR_CPP

/*
   File ControlSupervisor.cpp 

   This file has the implementation for class ControlSupervisor

   Felipe Viel <felipe.viel@posgrad.ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2021.
   Data da ultima alteracao: 10 de abril de 2021.

*/


//#include <iostream>
#include "ControlSupervisor.h"
#include <string>


//here we emulate the Bluetooth communication to get event list
std::string ControlSupervisor::readData(){
    unsigned char id;
    unsigned char y;
    unsigned char mo;
    unsigned char d;
    unsigned char h;
    unsigned char mi;
    unsigned char s;
    unsigned char pm;
    unsigned char eT;
    unsigned char cT;
    int statusSerial = 0;
    int endEvents = 0;

    std::string stringToReturn = "";

    statusSerial = serialCom.openSerial(2);
    if(statusSerial == 0){
        stringToReturn += "Opening serial ....\n";
    }
    if(statusSerial == 0){
        statusSerial = serialCom.sendData(); //used to advice that controller can send data;
        if(statusSerial == 0) {
            stringToReturn += "Starting read data ....\n";
        }
        endEvents = serialCom.readData(&id, &y, &mo, &d, &h, &mi, &s, &pm, &eT, &cT);
        if(endEvents == 0){
            dataProcessing.setNewEvent(id, y, mo, d, h, mi, s, pm, eT,cT);
        }
        stringToReturn += "End read data ....\n";
        serialCom.closeSerial();
        stringToReturn += "Closing serial ....\n";
    }
    return stringToReturn;
}

std::string ControlSupervisor::displayData( int optionDisplay, int start, int end, int month, int monthNumber){

    std::string stringToReturn;
    
    /*
    cout<<endl<<"What you want: "<<endl;
    cout<<"1 - Dislplay all events"<<endl;
    cout<<"2 - Display Events by date"<<endl;
    cout<<"3 - Display quantity of time (in minutes) that Heater Pool was used by date"<<endl;
    cout<<"4 - Display period of day most used"<<endl;
     */
    switch (optionDisplay){
        case 1: //Display all events
            stringToReturn = dataProcessing.getAllEvents();
            break;
        case 2: //List events by date
            stringToReturn = dataProcessing.getSpecificDateEvents(start, end, month, monthNumber);
            break;
        case 3: //Get used time bay dates interval
            stringToReturn = dataProcessing.getTimeUserDate(start, end, month, monthNumber);
            break;
        case 4: //get period most used (this function was not used - don't have space to more one button)
            stringToReturn = dataProcessing.getPeriodMostUsed();
            break;

        case 5: //create the false event list to be manipulate
            dataProcessing.setNewEvent(1, 21, 4, 11, 10, 30, 21, 0, LOG_EVENT_TURN_ON_AIR,0);
            dataProcessing.setNewEvent(1, 21, 4, 11, 15, 20, 22, 0, LOG_EVENT_DOOR_OPEN,0);
            dataProcessing.setNewEvent(1, 21, 4, 11, 15, 25, 22, 1, LOG_EVENT_TURN_OFF_AIR,0);
            dataProcessing.setNewEvent(1, 21, 4, 11, 14, 20, 22, 1, LOG_EVENT_DOOR_CLOSE,0);
            dataProcessing.setNewEvent(1, 21, 4, 15, 16, 50, 30, 1, LOG_EVENT_WINDOW_OPEN,0);
            dataProcessing.setNewEvent(1, 21, 4, 15, 16, 55, 30, 1, LOG_EVENT_WINDOW_CLOSE,0);
            dataProcessing.setNewEvent(1, 21, 4, 18, 16, 50, 30, 1, LOG_EVENT_TURN_ON_AIR,0);
            dataProcessing.setNewEvent(1, 21, 4, 18, 18, 20, 22, 0, LOG_EVENT_DOOR_OPEN,0);
            dataProcessing.setNewEvent(1, 21, 4, 18, 18, 25, 22, 1, LOG_EVENT_TURN_OFF_AIR,0);
            dataProcessing.setNewEvent(1, 21, 4, 18, 18, 26, 22, 0, LOG_EVENT_DOOR_OPEN,0);
            dataProcessing.setNewEvent(1, 21, 4, 19, 16, 50, 30, 1, LOG_EVENT_TURN_ON_AIR,0);
            dataProcessing.setNewEvent(1, 21, 4, 20, 18, 20, 22, 0, LOG_EVENT_DOOR_OPEN,0);
            dataProcessing.setNewEvent(1, 21, 4, 20, 18, 25, 22, 1, LOG_EVENT_TURN_OFF_AIR,0);
            dataProcessing.setNewEvent(1, 21, 4, 20, 18, 26, 22, 0, LOG_EVENT_DOOR_OPEN,0);
            break;

        default: stringToReturn = "Command not recgonize";
            break;
    }
    return stringToReturn;
    
}


#endif