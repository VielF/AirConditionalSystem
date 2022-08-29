#ifndef PROCESSINGDATALIST_H
#define PROCESSINGDATALIST_H
/*
   File ProcessingDataList.h 

   Header file for class ProcessingDataList

   Class is used to display events to supervisor

   Felipe Viel <felipe.viel@posgrad.ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2021.
   Data da ultima alteracao: 10 de abril de 2021.

*/


#include <iostream>
#include "List.cpp"
#include "libConfig.h"
#include <sstream>
#include <string>

using namespace std;

//TCont use to define data type of controller user, TSup define data used only in supervisor
template <class TCont, class TSup>
class ProcessingDataList{

    public:
        List eventsNode;
        TSup numEvents;

        TCont idController;
        TCont year;
        TCont month;
        TCont day;
        TCont hour;
        TCont min;
        TCont seg;
        TCont pm;
        TCont eventType;
        TCont configType;
    
        //method definition 
        ProcessingDataList();
        void getAllEvents();
        void listAll();
        TSup getQtdEvents();
        void getSpecificDateEvents(TSup DateStart, TSup dateEnd, TSup m,  TSup monthNumber);
        void getTimeUserDate(TSup DateStart, TSup dateEnd, TSup m,  TSup monthNumber);
        void setNewEvent(TCont id, TCont y, TCont mo, TCont d, TCont h, TCont mi, TCont s, TCont pm, TCont eT, TCont cT);
        void getPeriodMostUsed();
        void deleteEvents();
        friend std::ostream& operator<< (std::ostream& c, ProcessingDataList<TCont,TSup>& v){
            stringstream ss;
            string s;
            for(int i=1; i<=v.numEvents;i++){  //here a List all method version using friend and operator overlead
                v.eventsNode.readPosition(i-1,&v.idController, &v.year, &v.month, &v.day, &v.hour, &v.min, &v.seg, &v.pm, &v.eventType, &v.configType);
                switch (v.eventType){
                    case LOG_EVENT_TURN_ON_AIR:
                        c << "Event of device: "<< (TSup)v.idController << "- LOG_EVENT_TURN_ON_AIR: date: "<< (TSup)v.day << "-"<<(TSup)v.month<<"-"<<(TSup)v.year<<" - time: "<<(TSup)v.hour<<":"<<(TSup)v.min<<":"<<(TSup)v.seg<<endl;
                        //s.append(ss.str());
                        break;

                    case LOG_EVENT_TURN_OFF_AIR:
                        c << "Event of device: "<<(TSup)v.idController << "- LOG_EVENT_TURN_OFF_AIR: date: "<< (TSup)v.day << "-"<<(TSup)v.month<<"-"<<(TSup)v.year<<" - time: "<<(TSup)v.hour<<":"<<(TSup)v.min<<":"<<(TSup)v.seg<<endl;
                        //s.append(ss.str());
                        break;

                    case LOG_EVENT_DOOR_WINDOW_CLOSE:
                        c << "Event of device: "<<(TSup)v.idController << "- LOG_EVENT_DOOR_WINDOW_CLOSE: date: "<< (TSup)v.day << "-"<<(TSup)v.month<<"-"<<(TSup)v.year<<" - time: "<<(TSup)v.hour<<":"<<(TSup)v.min<<":"<<(TSup)v.seg<<endl;
                        //s.append(ss.str());
                        break;
                    
                    case LOG_EVENT_DOOR_WINDOW_OPEN:
                        c << "Event of device: "<<(TSup)v.idController << "- LOG_EVENT_DOOR_WINDOW_OPEN: date: "<< (TSup)v.day << "-"<<(TSup)v.month<<"-"<<(TSup)v.year<<" - time: "<<(TSup)v.hour<<":"<<(TSup)v.min<<":"<<(TSup)v.seg<<endl;
                        //s.append(ss.str());
                        break;
                    
                    case LOG_EVENT_DOOR_CLOSE:
                        c << "Event of device: "<<(TSup)v.idController << "- LOG_EVENT_DOOR_CLOSE: date: "<< (TSup)v.day << "-"<<(TSup)v.month<<"-"<<(TSup)v.year<<" - time: "<<(TSup)v.hour<<":"<<(TSup)v.min<<":"<<(TSup)v.seg<<endl;
                        //s.append(ss.str());
                        break;
                    
                    case LOG_EVENT_DOOR_OPEN:
                        c << "Event of device: "<<(TSup)v.idController << "- LOG_EVENT_DOOR_OPEN: date: "<< (TSup)v.day << "-"<<(TSup)v.month<<"-"<<(TSup)v.year<<" - time: "<<(TSup)v.hour<<":"<<(TSup)v.min<<":"<<(TSup)v.seg<<endl;
                        //s.append(ss.str());
                        break;

                    case LOG_EVENT_WINDOW_CLOSE:
                        c << "Event of device: "<<(TSup)v.idController << "- LOG_EVENT_WINDOW_CLOSE: date: "<< (TSup)v.day << "-"<<(TSup)v.month<<"-"<<(TSup)v.year<<" - time: "<<(TSup)v.hour<<":"<<(TSup)v.min<<":"<<(TSup)v.seg<<endl;
                        //s.append(ss.str());
                        break;

                    case LOG_EVENT_WINDOW_OPEN:
                        c << "Event of device: "<<(TSup)v.idController << "- LOG_EVENT_WINDOW_OPEN: date: "<< (TSup)v.day << "-"<<(TSup)v.month<<"-"<<(TSup)v.year<<" - time: "<<(TSup)v.hour<<":"<<(TSup)v.min<<":"<<(TSup)v.seg<<endl;
                        //s.append(ss.str());
                        break;

                    default: ss <<"Event not reconize\n";
                            //s.append(ss.str());
                            break;
                }
            }
            //c << s;
            return c;
        }

};

#endif