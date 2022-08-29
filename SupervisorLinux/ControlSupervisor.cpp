#ifndef CONTROLSUPERVISOR_CPP
#define CONTROLSUPERVISOR_CPP

/*
   File ControlSupervisor.cpp 

   This file has the implementation for class ControlSupervisor

   Felipe Viel <felipe.viel@posgrad.ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2021.
   Data da ultima alteracao: 29 de abril de 2021.

*/


#include <iostream>
#include "ControlSupervisor.h"


using namespace std;

//read events from control
template <class TCont, class TSup>
void ControlSupervisor<TCont, TSup>::readData(){
    TCont id; 
    TCont y; 
    TCont mo;
    TCont d; 
    TCont h; 
    TCont mi; 
    TCont s; 
    TCont pm; 
    TCont eT; 
    TCont cT;
    TSup statusSerial;
    TSup endEvents = 0;
    
    statusSerial = serialCom.openSerial(1);
    if(statusSerial == 0){
        serialCom.sendData(); //used to advice that controller can send data;

        while(endEvents == 0){
            endEvents = serialCom.readData(&id, &y, &mo, &d, &h, &mi, &s, &pm, &eT, &cT);
            if(endEvents == 0){
                dataProcessing.setNewEvent(id, y, mo, d, h, mi, s, pm, eT,cT);
            }
        }
        cout<<endl<<"End of reding events"<<endl;
        serialCom.closeSerial();
    }
}
//to display events by some opertation type
template <class TCont, class TSup>
void ControlSupervisor<TCont, TSup>::displayData(){
    TSup optionDisplay = 0;
    TSup month = 0;
    TSup monthNumber = 0;
    TSup startDate = 0, endDate = 0;
    

    cout<<endl<<"What you want: "<<endl;
    cout<<"1 - Dislplay all events"<<endl;
    cout<<"2 - Display Events by date"<<endl;
    cout<<"3 - Display quantity of time (in minutes) that Air-conditioner was used by date"<<endl;
    cout<<"4 - Display period of day most used"<<endl;
#ifdef DEBUG_MODE_PRINCIPAL
    //cout<<"5 - Insert virtual date to debug"<<endl;
#endif
    cout<<"Options: ";
    cin>>optionDisplay;
    switch (optionDisplay){
        case 1:
            /*
            Here you can use a method to print all events or you can overloading cout<< to print all event using
            the friend functio1n 
            */
            //dataProcessing.getAllEvents();
            //display all methods store in list 
            cout << dataProcessing;
            
            break;
        case 2: //to print events by period
            cout<<"\nIs by day (0) or by month (1): ";
            cin>>month;
            if(month == 0){
                cout<<"\nWhat is the month: ";
                cin>>monthNumber;
            }
            cout<<"\nWhat is the start date: ";
            cin>>startDate;
            cout<<"\nWhat is the end date: ";
            cin>>endDate;
            
            dataProcessing.getSpecificDateEvents(startDate, endDate, month, monthNumber);
            
            break;
        case 3: //to print hourns on 
            cout<<"\nIs by day (0) or by month (1): ";
            cin>>month;
            if(month == 0){
                cout<<"\nWhat is the month: ";
                cin>>monthNumber;
            }
            cout<<"\nWhat is the start date: ";
            cin>>startDate;
            cout<<"\nWhat is the end date: ";
            cin>>endDate;
;
            dataProcessing.getTimeUserDate(startDate, endDate, month, monthNumber);

            break;
        case 4: //to get period PM or AM most used
            dataProcessing.getPeriodMostUsed();
            break;
#ifdef DEBUG_MODE_PRINCIPAL
        case 5:
            //Adding syntetic data to emulate events in differt days and months
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
#endif
        default: cout<<endl<<"\nOptions not recognize\n";
            break;
    }
    
}

//to display events by some opertation type
template <class TCont, class TSup>
void ControlSupervisor<TCont, TSup>::control(){
    TSup optionInit = 0;

    while(optionInit != 3){ //FSM control until to use 3 option to exit
        switch (state){
            case stInit:  //state to init - used to something that is necessary in future implementations, now is only for menu;
                        cout<<endl<<"WELCOME TO AIR CONDITIONER LINUX SUPERVISOR"<<endl;
                        cout<<endl<<"What you want: "<<endl;
                        cout<<"1 - Read Events"<<endl;
                        cout<<"2 - Display Events"<<endl;
                        cout<<"3 - Exit"<<endl;
                        cout<<"Option: ";
                        cin>>optionInit;
                        if(optionInit == 1){
                            state = stReadData;
                        }else{
                            if(optionInit == 2){
                                state = stDisplayData;
                            }else{
                                state = stInit;
                            }        
                        }
                            
                        break;
            case stReadData:
                readData(); //get data to controller
                state = stInit;
                break;
            case stDisplayData:
                displayData(); //processing and diplay events read from controller
                state = stInit;
                break;

            default: state = stInit;
                    break;
        }
    }

}

#endif