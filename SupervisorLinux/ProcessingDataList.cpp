#ifndef PROCESSINGDATALIST_CPP
#define PROCESSINGDATALIST_CPP
/*
   File DataCommunicationLinux.h 

   This file has the implementation for class ProcessingDataList

   Felipe Viel <felipe.viel@posgrad.ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2021.
   Data da ultima alteracao: 29 de abril de 2021.

*/


#include <iostream>
#include "ProcessingDataList.h"


using namespace std;

//contructor 
template <class TCont, class TSup>
ProcessingDataList<TCont,TSup>::ProcessingDataList(){
    numEvents = 0;
    idController = 0;
    year = 0;
    month = 0;
    day = 0;
    hour = 0;
    min = 0;
    seg = 0;
    pm = 0;
    eventType = 0;
    configType = 0;
}

//to get the number os events read by the user
template <class TCont, class TSup>
TSup ProcessingDataList<TCont,TSup>::getQtdEvents(){
    return numEvents;
}

//List all events that was read without processing (number data)
template <class TCont, class TSup>
void ProcessingDataList<TCont,TSup>::listAll(){
    eventsNode.listAll();
}

//List all events that was read with processing 
template <class TCont, class TSup>
void ProcessingDataList<TCont,TSup>::getAllEvents(){
    for(int i=1; i<=numEvents;i++){
        eventsNode.readPosition(i-1,&idController, &year, &month, &day, &hour, &min, &seg, &pm, &eventType, &configType); //to read from list
        switch (eventType){
            case LOG_EVENT_TURN_ON_AIR:
                printf("Event of device: %u - LOG_EVENT_TURN_ON_AIR: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg); 
                break;

            case LOG_EVENT_TURN_OFF_AIR:
                printf("Event of device: %u - LOG_EVENT_TURN_OFF_AIR: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg); 
                break;

            case LOG_EVENT_DOOR_WINDOW_CLOSE:
                printf("Event of device: %u - LOG_EVENT_DOOR_WINDOW_CLOSE: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg); 
                break;
            
            case LOG_EVENT_DOOR_WINDOW_OPEN:
                printf("Event of device: %u - LOG_EVENT_DOOR_WINDOW_OPEN: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg); 
                break;
            
            case LOG_EVENT_DOOR_CLOSE:
                printf("Event of device: %u - LOG_EVENT_DOOR_CLOSE: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg); 
                break;
            
            case LOG_EVENT_DOOR_OPEN:
                printf("Event of device: %u - LOG_EVENT_DOOR_OPEN: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg); 
                break;

            case LOG_EVENT_WINDOW_CLOSE:
                printf("Event of device: %u - LOG_EVENT_WINDOW_CLOSE: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg); 
                break;

            case LOG_EVENT_WINDOW_OPEN:
                printf("Event of device: %u - LOG_EVENT_WINDOW_OPEN: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg); 
                break;

            default: printf("Event not reconize\n");
                    break;
        }
    }
}


//get events between start and end data, that can be between two days (month = 0) or between two months (month = 1)
template <class TCont, class TSup>
void ProcessingDataList<TCont,TSup>::getSpecificDateEvents(TSup DateStart, TSup dateEnd, TSup m, TSup monthNumber){
    for(int i=1; i<=numEvents;i++){
        if(m == 0){
            eventsNode.readPosition(i-1,&idController, &year, &month, &day, &hour, &min, &seg, &pm, &eventType, &configType); //to read list
            if(day >= (TCont)DateStart && day <= (TCont)dateEnd  && monthNumber == month){  //identify if is in the day (and month) date interval to list
                switch (eventType){
                    case LOG_EVENT_TURN_ON_AIR:
                        printf("Event of device: %u - LOG_EVENT_TURN_ON_AIR: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg); 
                        break;

                    case LOG_EVENT_TURN_OFF_AIR:
                        printf("Event of device: %u - LOG_EVENT_TURN_OFF_AIR: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg); 
                        break;

                    case LOG_EVENT_DOOR_WINDOW_CLOSE:
                        printf("Event of device: %u - LOG_EVENT_DOOR_WINDOW_CLOSE: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg); 
                        break;
                    
                    case LOG_EVENT_DOOR_WINDOW_OPEN:
                        printf("Event of device: %u - LOG_EVENT_DOOR_WINDOW_OPEN: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg); 
                        break;
                    
                    case LOG_EVENT_DOOR_CLOSE:
                        printf("Event of device: %u - LOG_EVENT_DOOR_CLOSE: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg); 
                        break;
                    
                    case LOG_EVENT_DOOR_OPEN:
                        printf("Event of device: %u - LOG_EVENT_DOOR_OPEN: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg); 
                        break;

                    case LOG_EVENT_WINDOW_CLOSE:
                        printf("Event of device: %u - LOG_EVENT_WINDOW_CLOSE: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg); 
                        break;

                    case LOG_EVENT_WINDOW_OPEN:
                        printf("Event of device: %u - LOG_EVENT_WINDOW_OPEN: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg); 
                        break;

                    default: printf("Event not reconize\n");
                            break;
                }
                
            }
        }else{
            eventsNode.readPosition(i-1,&idController, &year, &month, &day, &hour, &min, &seg, &pm, &eventType, &configType); //to read list
            if(month >= (TCont)DateStart && month <= (TCont)dateEnd){ //identify if is in the  month date interval to list
                switch (eventType){
                    case LOG_EVENT_TURN_ON_AIR:
                        printf("Event of device: %u - LOG_EVENT_TURN_ON_AIR: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg); 
                        break;

                    case LOG_EVENT_TURN_OFF_AIR:
                        printf("Event of device: %u - LOG_EVENT_TURN_OFF_AIR: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg); 
                        break;

                    case LOG_EVENT_DOOR_WINDOW_CLOSE:
                        printf("Event of device: %u - LOG_EVENT_DOOR_WINDOW_CLOSE: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg); 
                        break;
                    
                    case LOG_EVENT_DOOR_WINDOW_OPEN:
                        printf("Event of device: %u - LOG_EVENT_DOOR_WINDOW_OPEN: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg); 
                        break;
                    
                    case LOG_EVENT_DOOR_CLOSE:
                        printf("Event of device: %u - LOG_EVENT_DOOR_CLOSE: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg); 
                        break;
                    
                    case LOG_EVENT_DOOR_OPEN:
                        printf("Event of device: %u - LOG_EVENT_DOOR_OPEN: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg); 
                        break;

                    case LOG_EVENT_WINDOW_CLOSE:
                        printf("Event of device: %u - LOG_EVENT_WINDOW_CLOSE: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg); 
                        break;

                    case LOG_EVENT_WINDOW_OPEN:
                        printf("Event of device: %u - LOG_EVENT_WINDOW_OPEN: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg); 
                        break;

                    default: printf("Event not reconize\n");
                            break;
                }
                
            }
                
        }
    }


}
//get events between start and end data, that can be between two days (m = 0) or between two months (m = 1)
template <class TCont, class TSup>
void ProcessingDataList<TCont, TSup>::getTimeUserDate(TSup DateStart, TSup dateEnd, TSup m,  TSup monthNumber){
    TSup minutesUsed = 0;
    TSup disable = 0;
    TSup on_hour;
    TSup on_min;
    TSup on_day;
    int i = 1;
    while(i<=numEvents){
        if(m == 0){ //if the calculus is by day
            eventsNode.readPosition(i-1,&idController, &year, &month, &day, &hour, &min, &seg, &pm, &eventType, &configType); //get data from list
            if(day >= (TCont)DateStart && day <= (TCont)dateEnd && (TCont)monthNumber == month){
                if(LOG_EVENT_TURN_ON_AIR == eventType){ //veryfy is event is turn on power
                    on_hour = (TSup)hour;
                    on_min = (TSup)min;
                    on_day = (TSup)day;
                    cout<<"On - Date: "<<on_day<<" - Hour: "<<on_hour<<" min: "<<on_min<<endl;
                    while(disable == 0){
                        i++;
                        eventsNode.readPosition(i-1,&idController, &year, &month, &day, &hour, &min, &seg, &pm, &eventType, &configType); //get data from list
                        if(LOG_EVENT_TURN_OFF_AIR == eventType){ //veryfy is event is turn off power
                            cout<<"Off - Date: "<<(TSup)day<<" - Hour: "<<(TSup)hour<<" min: "<<(TSup)min<<endl;
                            disable = 1;
                            if((TSup)day == on_day){  //verify if state change is in the same day
                                if((TSup)hour == on_hour){
                                    minutesUsed += (TSup)min - on_min;
                                }else{
                                    minutesUsed += 60*((TSup)hour - on_hour) + ((TSup)min - on_min);
                                    
                                }
                            }else{ //verify if state change is in different days
                                if(((TSup)hour == on_hour)){
                                    minutesUsed += 1440 + ((TSup)min - on_min);
                                }else{
                                    if((TSup)hour < on_hour){
                                        minutesUsed += 1440 + (on_hour - (TSup)hour)*60 + ((TSup)min - on_min);     
                                    }else{
                                        minutesUsed += 1440 + ((TSup)hour - on_hour)*60 + ((TSup)min - on_min);
                                    }
                                   
                                }
                            }

                        }
                    }
                    disable = 0;
                }
                
            }
        }else{ //if the calculus is by day
            eventsNode.readPosition(i-1,&idController, &year, &month, &day, &hour, &min, &seg, &pm, &eventType, &configType); //get data from list
            if(month >= (TCont)DateStart && month <= (TCont)dateEnd){
                if(LOG_EVENT_TURN_ON_AIR == eventType){ //veryfy is event is turn on power
                    on_hour = (TSup)hour;
                    on_min = (TSup)min;
                    on_day = (TSup)day;
                    while(disable == 0){
                        i++;
                        eventsNode.readPosition(i-1,&idController, &year, &month, &day, &hour, &min, &seg, &pm, &eventType, &configType); //get data from list
                        if(LOG_EVENT_TURN_OFF_AIR == eventType){ //veryfy is event is turn off power
                            disable = 1;
                            if((TSup)day == on_day){
                                if((TSup)hour == on_hour){ //veryfy is event is turn off power 
                                    minutesUsed += (TSup)min - on_min;
                                }else{
                                    minutesUsed += 60 + ((TSup)min - on_min);
                                }
                            }else{
                                if(((TSup)hour == on_hour)){ //verify if state change is in different days
                                    minutesUsed += 1440 + ((TSup)min - on_min);
                                }else{
                                    if((TSup)hour < on_hour){
                                        minutesUsed += 1440 + (on_hour - (TSup)hour)*60 + ((TSup)min - on_min);     
                                    }else{
                                        minutesUsed += 1440 + ((TSup)hour - on_hour)*60 + ((TSup)min - on_min);
                                    }
                                   
                                }
                            }

                        }
                    }
                    disable = 0;
                }
            }
        }
        i++;
    }
    cout<<"Minutes = "<<minutesUsed<<endl;
    if(m == 0){
        cout<<endl<<"The heater was used "<<(TSup)(minutesUsed/60)<< "h and "<<(TSup)(minutesUsed%60)<<"min between days "<< DateStart <<" and "<< dateEnd<<endl;
    }else{
        cout<<endl<<"The heater was used "<<(TSup)(minutesUsed/60)<< "h and "<<(TSup)(minutesUsed%60)<<"min between days "<< DateStart <<" and "<< dateEnd<<endl;
    }
}

//verify what PM or AM period was the most used (turn on)
template <class TCont, class TSup>
void ProcessingDataList<TCont, TSup>::getPeriodMostUsed(){
    TSup amCount = 0;
    TSup pmCount = 0;
    for(int i=1; i<=numEvents;i++){
        eventsNode.readPosition(i-1,&idController, &year, &month, &day, &hour, &min, &seg, &pm, &eventType, &configType);
        if(LOG_EVENT_TURN_ON_AIR == eventType){
            if(pm == 0){
                amCount++;
            }else{
                pmCount++;
            }
        }
    }
    if(pmCount > amCount){
        cout<<endl<<"The period that Heater Pool was most used is PM"<<endl;
    }else{
        if(pmCount < amCount){
            cout<<endl<<"The period that Heater Pool was most used is AM"<<endl;
        }else{
             cout<<endl<<"The period that Heater Pool was equal in AM and PM"<<endl;
        }
    }
}

//to exclude event form List (all)
template <class TCont, class TSup>
void ProcessingDataList<TCont, TSup>::deleteEvents(){
    TSup nEventAux = numEvents;
    for(int i=1; i<=nEventAux;i++){
        eventsNode.removeFirst();
        numEvents--;
    }
    

}

//set a new event to List
template <class TCont, class TSup>
void ProcessingDataList<TCont, TSup>::setNewEvent(TCont id, TCont y, TCont mo, TCont d, TCont h, TCont mi, TCont s, TCont pm, TCont eT, TCont cT){
    eventsNode.insertAfterLast(id,y, mo, d, h, mi, s, pm, eT, cT);
    numEvents++;
}


#endif