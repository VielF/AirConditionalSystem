#ifndef DATACOMMUNICATIONLINUX_CPP
#define DATACOMMUNICATIONLINUX_CPP
/*
   File DataCommunicationAndroid.h

   This file has the implementation for class DataCommunicationLinux

   Felipe Viel <felipe.viel@posgrad.ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2021.
   Data da ultima alteracao: 10 de abril de 2021.

*/

#include "DataCommunicationAndroid.h"






int DataCommunicationAndroid::openSerial(int port){
    /*
     * Here to need implement bluetooth open communication like serial
     */
    return 0; //only to do something
}
//send serial data
int DataCommunicationAndroid::sendData(){
    /*
     * Here to need implement bluetooth data send to controller
     */

    return 0; //only to do something
}

//read serial data

int DataCommunicationAndroid::readData(unsigned char* id, unsigned char* y, unsigned char* mo, unsigned char* d, unsigned char* h, unsigned char* mi, unsigned char* s, unsigned char* pm, unsigned char* eT, unsigned char* cT){
    /*
     * area to implement bluetooth communication and get data from controller
     */
    unsigned char buf[12] = {LOG_HEADING,DEVICE_ID_LOG, 21, 4,12,9,30,10,0,LOG_EVENT_WINDOW_CLOSE,0,LOG_END_EVENT_TRANSMISSION};
    int res;

        if(((unsigned char)buf[11] != LOG_END_EVENT_LIST) && ((unsigned char)buf[0] == LOG_HEADING) && ((unsigned char)buf[11] == LOG_END_EVENT_TRANSMISSION)){

            // buf[0] = LOG_HEADING
            *id = (unsigned char)buf[1];   // buf[1] = DEVICE_ID_LOG
            *y  = (unsigned char)buf[2];   // buf[2] = year
            *mo = (unsigned char)buf[3];   // buf[3] = month
            *d  = (unsigned char)buf[4];   // buf[4] = day
            *h  = (unsigned char)buf[5];   // buf[5] = hour
            *mi = (unsigned char)buf[6];   // buf[6] = min
            *s  = (unsigned char)buf[7];   // buf[7] = seg
            *pm = (unsigned char)buf[8];   // buf[8] = pm
            *eT = (unsigned char)buf[9];   // buf[9] = eventType
            *cT = (unsigned char)buf[10];  // buf[10] = configType
            // buf[11] = LOG_END_EVENT_TRANSMISSION
            //printf("\nDEBUG DataCommunicationLinux : Entrei readData: %u - %u:%u:%u:%u:%u:%u:%u:%u:%u",(unsigned char)buf[1], (unsigned char)buf[2], (unsigned char)buf[3], (unsigned char)buf[4], (unsigned char)buf[5], (unsigned char)buf[6],
                   //(unsigned char)buf[7], (unsigned char)buf[8], (unsigned char)buf[9], (unsigned char)buf[10]);
            return 0; //have data to collet yet
        }else{
            return 1; //end list
        }

}


int DataCommunicationAndroid::closeSerial(){
    /*
     * Here to need implement bluetooth close communication (if necessary)
     */
    return 0; //only to do something
}

#endif