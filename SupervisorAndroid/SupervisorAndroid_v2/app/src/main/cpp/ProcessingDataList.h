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


//#include <iostream>
#include "List.cpp"
#include "libConfig.h"
#include <sstream>
#include <string>



//TCont use to define data type of controller user, TSup define data used only in supervisor
class ProcessingDataList{
    public:
        List eventsNode;
        int numEvents;

        unsigned char idController;
        unsigned char year;
        unsigned char month;
        unsigned char day;
        unsigned char  hour;
        unsigned char  min;
        unsigned char  seg;
        unsigned char  pm;
        unsigned char  eventType;
        unsigned char  configType;
    
         
        ProcessingDataList();
        std::string getAllEvents();
        void listAll();
        int getQtdEvents();
        std::string getSpecificDateEvents(int DateStart, int dateEnd, int m,  int monthNumber);
        std::string getTimeUserDate(int DateStart, int dateEnd, int m,  int monthNumber);
        void setNewEvent(unsigned char  id, unsigned char  y, unsigned char  mo, unsigned char  d, unsigned char  h, unsigned char  mi, unsigned char  s, unsigned char  pm, unsigned char  eT, unsigned char  cT);
        std::string getPeriodMostUsed();
        void deleteEvents();


};

#endif