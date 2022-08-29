#ifndef PROCESSINGDATALIST_CPP
#define PROCESSINGDATALIST_CPP
/*
   File ProcessingDataList.h

   This file has the implementation for class ProcessingDataList

   Felipe Viel <felipe.viel@posgrad.ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2021.
   Data da ultima alteracao: 10 de abril de 2021.

*/


//#include <iostream>
#include "ProcessingDataList.h"





ProcessingDataList::ProcessingDataList(){
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


int ProcessingDataList::getQtdEvents(){
    return numEvents;
}


void ProcessingDataList::listAll(){
    eventsNode.listAll();
}


std::string ProcessingDataList::getAllEvents(){
    std::string stringToReturn = "";

    for(int i=1; i<=numEvents;i++){
        eventsNode.readPosition(i-1,&idController, &year, &month, &day, &hour, &min, &seg, &pm, &eventType, &configType);
        switch (eventType){
            case LOG_EVENT_TURN_ON_AIR:
                stringToReturn += "ID:"+std::to_string((int)idController)+"- LOGE_TURN_ON_AIR: date: "
                                  +std::to_string((int)day)+"-"+std::to_string((int)month)+"-"+std::to_string((int)year)+" - time: "
                                  +std::to_string((int)hour)+":"+std::to_string((int)min)+":"+std::to_string((int)seg)+"\n";
                break;

            case LOG_EVENT_TURN_OFF_AIR:
                stringToReturn += "ID:"+std::to_string((int)idController)+"- LOGE_TURN_OFF_AIR: date: "
                                  +std::to_string((int)day)+"-"+std::to_string((int)month)+"-"+std::to_string((int)year)+" - time: "
                                  +std::to_string((int)hour)+":"+std::to_string((int)min)+":"+std::to_string((int)seg)+"\n";
                //printf("Event of device: %u - LOG_EVENT_TURN_OFF_AIR: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg);
                break;

            case LOG_EVENT_DOOR_WINDOW_CLOSE:
                stringToReturn += "ID:"+std::to_string((int)idController)+"- LOGE_DOOR_WINDOW_CLOSE: date: "
                                  +std::to_string((int)day)+"-"+std::to_string((int)month)+"-"+std::to_string((int)year)+" - time: "
                                  +std::to_string((int)hour)+":"+std::to_string((int)min)+":"+std::to_string((int)seg)+"\n";
                //printf("Event of device: %u - LOG_EVENT_DOOR_WINDOW_CLOSE: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg);
                break;

            case LOG_EVENT_DOOR_WINDOW_OPEN:
                stringToReturn += "ID:"+std::to_string((int)idController)+"- LOGE_DOOR_WINDOW_OPEN: date: "
                                  +std::to_string((int)day)+"-"+std::to_string((int)month)+"-"+std::to_string((int)year)+" - time: "
                                  +std::to_string((int)hour)+":"+std::to_string((int)min)+":"+std::to_string((int)seg)+"\n";
                //printf("Event of device: %u - LOG_EVENT_DOOR_WINDOW_OPEN: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg);
                break;

            case LOG_EVENT_DOOR_CLOSE:
                stringToReturn += "ID:"+std::to_string((int)idController)+"- LOGE_DOOR_CLOSE: date: "
                                  +std::to_string((int)day)+"-"+std::to_string((int)month)+"-"+std::to_string((int)year)+" - time: "
                                  +std::to_string((int)hour)+":"+std::to_string((int)min)+":"+std::to_string((int)seg)+"\n";
                //printf("Event of device: %u - LOG_EVENT_DOOR_CLOSE: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg);
                break;

            case LOG_EVENT_DOOR_OPEN:
                stringToReturn += "ID:"+std::to_string((int)idController)+"- LOGE_DOOR_OPEN: date: "
                                  +std::to_string((int)day)+"-"+std::to_string((int)month)+"-"+std::to_string((int)year)+" - time: "
                                  +std::to_string((int)hour)+":"+std::to_string((int)min)+":"+std::to_string((int)seg)+"\n";
                //printf("Event of device: %u - LOG_EVENT_DOOR_OPEN: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg);
                break;

            case LOG_EVENT_WINDOW_CLOSE:
                stringToReturn += "ID:"+std::to_string((int)idController)+"- LOGE_WINDOW_CLOSE: date: "
                                  +std::to_string((int)day)+"-"+std::to_string((int)month)+"-"+std::to_string((int)year)+" - time: "
                                  +std::to_string((int)hour)+":"+std::to_string((int)min)+":"+std::to_string((int)seg)+"\n";
                //printf("Event of device: %u - LOG_EVENT_WINDOW_CLOSE: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg);
                break;

            case LOG_EVENT_WINDOW_OPEN:
                stringToReturn += "ID:"+std::to_string((int)idController)+"- LOGE_WINDOW_OPEN: date: "
                                  +std::to_string((int)day)+"-"+std::to_string((int)month)+"-"+std::to_string((int)year)+" - time: "
                                  +std::to_string((int)hour)+":"+std::to_string((int)min)+":"+std::to_string((int)seg)+"\n";
                //printf("Event of device: %u - LOG_EVENT_WINDOW_OPEN: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg);
                break;

            default: stringToReturn += "Event not reconize\n";
                break;
        }
    }

    return stringToReturn;
}


//get events between start and end data, that can be between two days (month = 0) or between two months (month = 1)
std::string ProcessingDataList::getSpecificDateEvents(int DateStart, int dateEnd, int m, int monthNumber){
    std::string stringToReturn = "";

    for(int i=1; i<=numEvents;i++){
        if(m == 0){
            eventsNode.readPosition(i-1,&idController, &year, &month, &day, &hour, &min, &seg, &pm, &eventType, &configType);
            if(day >= (unsigned char )DateStart && day <= (unsigned char )dateEnd  && monthNumber == month){
                switch (eventType){
                    case LOG_EVENT_TURN_ON_AIR:
                        stringToReturn += "ID:"+std::to_string((int)idController)+"- LOGE_TURN_ON_AIR: date: "
                                          +std::to_string((int)day)+"-"+std::to_string((int)month)+"-"+std::to_string((int)year)+" - time: "
                                          +std::to_string((int)hour)+":"+std::to_string((int)min)+":"+std::to_string((int)seg)+"\n";
                        break;

                    case LOG_EVENT_TURN_OFF_AIR:
                        stringToReturn += "ID:"+std::to_string((int)idController)+"- LOGE_TURN_OFF_AIR: date: "
                                          +std::to_string((int)day)+"-"+std::to_string((int)month)+"-"+std::to_string((int)year)+" - time: "
                                          +std::to_string((int)hour)+":"+std::to_string((int)min)+":"+std::to_string((int)seg)+"\n";
                        //printf("Event of device: %u - LOG_EVENT_TURN_OFF_AIR: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg);
                        break;

                    case LOG_EVENT_DOOR_WINDOW_CLOSE:
                        stringToReturn += "ID:"+std::to_string((int)idController)+"- LOGE_DOOR_WINDOW_CLOSE: date: "
                                          +std::to_string((int)day)+"-"+std::to_string((int)month)+"-"+std::to_string((int)year)+" - time: "
                                          +std::to_string((int)hour)+":"+std::to_string((int)min)+":"+std::to_string((int)seg)+"\n";
                        //printf("Event of device: %u - LOG_EVENT_DOOR_WINDOW_CLOSE: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg);
                        break;

                    case LOG_EVENT_DOOR_WINDOW_OPEN:
                        stringToReturn += "ID:"+std::to_string((int)idController)+"- LOGE_DOOR_WINDOW_OPEN: date: "
                                          +std::to_string((int)day)+"-"+std::to_string((int)month)+"-"+std::to_string((int)year)+" - time: "
                                          +std::to_string((int)hour)+":"+std::to_string((int)min)+":"+std::to_string((int)seg)+"\n";
                        //printf("Event of device: %u - LOG_EVENT_DOOR_WINDOW_OPEN: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg);
                        break;

                    case LOG_EVENT_DOOR_CLOSE:
                        stringToReturn += "ID:"+std::to_string((int)idController)+"- LOGE_DOOR_CLOSE: date: "
                                          +std::to_string((int)day)+"-"+std::to_string((int)month)+"-"+std::to_string((int)year)+" - time: "
                                          +std::to_string((int)hour)+":"+std::to_string((int)min)+":"+std::to_string((int)seg)+"\n";
                        //printf("Event of device: %u - LOG_EVENT_DOOR_CLOSE: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg);
                        break;

                    case LOG_EVENT_DOOR_OPEN:
                        stringToReturn += "ID:"+std::to_string((int)idController)+"- LOGE_DOOR_OPEN: date: "
                                          +std::to_string((int)day)+"-"+std::to_string((int)month)+"-"+std::to_string((int)year)+" - time: "
                                          +std::to_string((int)hour)+":"+std::to_string((int)min)+":"+std::to_string((int)seg)+"\n";
                        //printf("Event of device: %u - LOG_EVENT_DOOR_OPEN: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg);
                        break;

                    case LOG_EVENT_WINDOW_CLOSE:
                        stringToReturn += "ID:"+std::to_string((int)idController)+"- LOGE_WINDOW_CLOSE: date: "
                                          +std::to_string((int)day)+"-"+std::to_string((int)month)+"-"+std::to_string((int)year)+" - time: "
                                          +std::to_string((int)hour)+":"+std::to_string((int)min)+":"+std::to_string((int)seg)+"\n";
                        //printf("Event of device: %u - LOG_EVENT_WINDOW_CLOSE: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg);
                        break;

                    case LOG_EVENT_WINDOW_OPEN:
                        stringToReturn += "ID:"+std::to_string((int)idController)+"- LOGE_WINDOW_OPEN: date: "
                                          +std::to_string((int)day)+"-"+std::to_string((int)month)+"-"+std::to_string((int)year)+" - time: "
                                          +std::to_string((int)hour)+":"+std::to_string((int)min)+":"+std::to_string((int)seg)+"\n";
                        //printf("Event of device: %u - LOG_EVENT_WINDOW_OPEN: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg);
                        break;

                    default: stringToReturn += "Event not reconize\n";
                        break;
                }
                
            }
        }else{
            eventsNode.readPosition(i-1,&idController, &year, &month, &day, &hour, &min, &seg, &pm, &eventType, &configType);
            if(month >= (unsigned char )DateStart && month <= (unsigned char )dateEnd){
                switch (eventType){
                    case LOG_EVENT_TURN_ON_AIR:
                        stringToReturn += "ID:"+std::to_string((int)idController)+"- LOGE_TURN_ON_AIR: date: "
                                          +std::to_string((int)day)+"-"+std::to_string((int)month)+"-"+std::to_string((int)year)+" - time: "
                                          +std::to_string((int)hour)+":"+std::to_string((int)min)+":"+std::to_string((int)seg)+"\n";
                        break;

                    case LOG_EVENT_TURN_OFF_AIR:
                        stringToReturn += "ID:"+std::to_string((int)idController)+"- LOGE_TURN_OFF_AIR: date: "
                                          +std::to_string((int)day)+"-"+std::to_string((int)month)+"-"+std::to_string((int)year)+" - time: "
                                          +std::to_string((int)hour)+":"+std::to_string((int)min)+":"+std::to_string((int)seg)+"\n";
                        //printf("Event of device: %u - LOG_EVENT_TURN_OFF_AIR: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg);
                        break;

                    case LOG_EVENT_DOOR_WINDOW_CLOSE:
                        stringToReturn += "ID:"+std::to_string((int)idController)+"- LOGE_DOOR_WINDOW_CLOSE: date: "
                                          +std::to_string((int)day)+"-"+std::to_string((int)month)+"-"+std::to_string((int)year)+" - time: "
                                          +std::to_string((int)hour)+":"+std::to_string((int)min)+":"+std::to_string((int)seg)+"\n";
                        //printf("Event of device: %u - LOG_EVENT_DOOR_WINDOW_CLOSE: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg);
                        break;

                    case LOG_EVENT_DOOR_WINDOW_OPEN:
                        stringToReturn += "ID:"+std::to_string((int)idController)+"- LOGE_DOOR_WINDOW_OPEN: date: "
                                          +std::to_string((int)day)+"-"+std::to_string((int)month)+"-"+std::to_string((int)year)+" - time: "
                                          +std::to_string((int)hour)+":"+std::to_string((int)min)+":"+std::to_string((int)seg)+"\n";
                        //printf("Event of device: %u - LOG_EVENT_DOOR_WINDOW_OPEN: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg);
                        break;

                    case LOG_EVENT_DOOR_CLOSE:
                        stringToReturn += "ID:"+std::to_string((int)idController)+"- LOGE_DOOR_CLOSE: date: "
                                          +std::to_string((int)day)+"-"+std::to_string((int)month)+"-"+std::to_string((int)year)+" - time: "
                                          +std::to_string((int)hour)+":"+std::to_string((int)min)+":"+std::to_string((int)seg)+"\n";
                        //printf("Event of device: %u - LOG_EVENT_DOOR_CLOSE: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg);
                        break;

                    case LOG_EVENT_DOOR_OPEN:
                        stringToReturn += "ID:"+std::to_string((int)idController)+"- LOGE_DOOR_OPEN: date: "
                                          +std::to_string((int)day)+"-"+std::to_string((int)month)+"-"+std::to_string((int)year)+" - time: "
                                          +std::to_string((int)hour)+":"+std::to_string((int)min)+":"+std::to_string((int)seg)+"\n";
                        //printf("Event of device: %u - LOG_EVENT_DOOR_OPEN: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg);
                        break;

                    case LOG_EVENT_WINDOW_CLOSE:
                        stringToReturn += "ID:"+std::to_string((int)idController)+"- LOGE_WINDOW_CLOSE: date: "
                                          +std::to_string((int)day)+"-"+std::to_string((int)month)+"-"+std::to_string((int)year)+" - time: "
                                          +std::to_string((int)hour)+":"+std::to_string((int)min)+":"+std::to_string((int)seg)+"\n";
                        //printf("Event of device: %u - LOG_EVENT_WINDOW_CLOSE: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg);
                        break;

                    case LOG_EVENT_WINDOW_OPEN:
                        stringToReturn += "ID:"+std::to_string((int)idController)+"- LOGE_WINDOW_OPEN: date: "
                                          +std::to_string((int)day)+"-"+std::to_string((int)month)+"-"+std::to_string((int)year)+" - time: "
                                          +std::to_string((int)hour)+":"+std::to_string((int)min)+":"+std::to_string((int)seg)+"\n";
                        //printf("Event of device: %u - LOG_EVENT_WINDOW_OPEN: date: %u-%u-%u - time: %u:%u:%u\n",idController, day, month, year,hour, min, seg);
                        break;

                    default: stringToReturn += "Event not reconize\n";
                        break;
                }
                
            }
                
        }
    }

    return stringToReturn;

}
//get events between start and end data, that can be between two days (m = 0) or between two months (m = 1)
std::string ProcessingDataList::getTimeUserDate(int DateStart, int dateEnd, int m,  int monthNumber){
    int minutesUsed = 0;
    int disable = 0;
    std::string stringToReturn = "";
    int  on_hour;
    int  on_min;
    int  on_day;
    int i = 1;
    while(i<=numEvents){
        if(m == 0){
            eventsNode.readPosition(i-1,&idController, &year, &month, &day, &hour, &min, &seg, &pm, &eventType, &configType);
            if((int)day >= DateStart && (int)day <= dateEnd && monthNumber == (int)month){
                if(LOG_EVENT_TURN_ON_AIR == eventType){
                    on_hour = (int)hour;
                    on_min = (int)min;
                    on_day = (int)day;

                    while(disable == 0){
                        i++;
                        eventsNode.readPosition(i-1,&idController, &year, &month, &day, &hour, &min, &seg, &pm, &eventType, &configType);
                        if(LOG_EVENT_TURN_OFF_AIR == eventType){

                            disable = 1;
                            if((int)day == on_day){
                                if((int)hour == on_hour){
                                    minutesUsed += (int)min - on_min;
                                }else{
                                    minutesUsed += 60*((int)hour - on_hour) + ((int)min - on_min);

                                }
                            }else{
                                if(((int)hour == on_hour)){
                                    minutesUsed += 1440 + ((int)min - on_min);
                                }else{
                                    if((int)hour < on_hour){
                                        minutesUsed += 1440 + (on_hour - (int)hour)*60 + ((int)min - on_min);
                                    }else{
                                        minutesUsed += 1440 + ((int)hour - on_hour)*60 + ((int)min - on_min);
                                    }

                                }
                            }

                        }
                    }
                    disable = 0;
                }
                
            }
        }else{
            eventsNode.readPosition(i-1,&idController, &year, &month, &day, &hour, &min, &seg, &pm, &eventType, &configType);
            if((int)month >= DateStart && (int)month <= dateEnd){
                if(LOG_EVENT_TURN_ON_AIR == eventType){
                    on_hour = (int)hour;
                    on_min = (int)min;
                    on_day = (int)day;
                    while(disable == 0){
                        i++;
                        eventsNode.readPosition(i-1,&idController, &year, &month, &day, &hour, &min, &seg, &pm, &eventType, &configType);
                        if(LOG_EVENT_TURN_OFF_AIR == eventType){
                            disable = 1;
                            if((int)day == on_day){
                                if((int)hour == on_hour){
                                    minutesUsed += (int)min - on_min;
                                }else{
                                    minutesUsed += 60*((int)hour - on_hour) + ((int)min - on_min);
                                }
                            }else{
                                if((hour == on_hour)){
                                    minutesUsed += 1440 + ((int)min - on_min);
                                }else{
                                    if((int)hour < on_hour){
                                        minutesUsed += 1440 + (on_hour - (int)hour)*60 + ((int)min - on_min);
                                    }else{
                                        minutesUsed += 1440 + ((int)hour - on_hour)*60 + ((int)min - on_min);
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
    if(m == 0){
        stringToReturn = "The heater was used "+std::to_string((int)(minutesUsed/60))+"h and "
                         +std::to_string((int)(minutesUsed%60))+"min between days "+std::to_string(DateStart)+" and "+std::to_string(dateEnd)
                         +" of month "+std::to_string(monthNumber)+"\n";
    }else{
        stringToReturn = "The heater was used "+std::to_string((int)(minutesUsed/60))+"h and "
                         +std::to_string((int)(minutesUsed%60))+"min between months "+std::to_string(DateStart)+" and "+std::to_string(dateEnd)+"\n";
    }

    return stringToReturn;
}



std::string  ProcessingDataList::getPeriodMostUsed(){
    int amCount = 0;
    int pmCount = 0;
    std::string stringToReturn = "";
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
        stringToReturn = "The period that Heater Pool was most used is PM\n";
    }else{
        if(pmCount < amCount){
            stringToReturn = "The period that Heater Pool was most used is AM\n";
        }else{
            stringToReturn = "The period that Heater Pool was equal in AM and PM\n";
        }
    }
}


void ProcessingDataList::deleteEvents(){
    int nEventAux = numEvents;
    for(int i=1; i<=nEventAux;i++){
        eventsNode.removeFirst();
        numEvents--;
    }
    

}

void ProcessingDataList::setNewEvent(unsigned char  id, unsigned char  y, unsigned char  mo, unsigned char  d, unsigned char  h, unsigned char  mi, unsigned char  s, unsigned char  pm, unsigned char  eT, unsigned char  cT){
    eventsNode.insertAfterLast(id,y, mo, d, h, mi, s, pm, eT, cT);
    numEvents++;
}

#endif