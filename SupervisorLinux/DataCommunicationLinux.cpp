#ifndef DATACOMMUNICATIONLINUX_CPP
#define DATACOMMUNICATIONLINUX_CPP
/*
   File DataCommunicationLinux.h 

   This file has the implementation for class DataCommunicationLinux

   Felipe Viel <felipe.viel@posgrad.ufsc.br>
   Departamento de Engenharia Eletrica

   Data da criacao: Abril de 2021.
   Data da ultima alteracao: 10 de abril de 2021.

*/


#include <iostream>
#include "DataCommunicationLinux.h"


using namespace std;

// Open Serial port 1 -  "/dev/ttyUSB0" or 2 - "/dev/ttyUSB1";
template <class TCont, class TSup>
TSup DataCommunicationLinux<TCont, TSup>::openSerial(TSup port){
    // serial names
    const char *com1="/dev/ttyUSB0", *com2="/dev/ttyUSB1";

    struct termios options;
    switch(port) {
        case 1: strcpy(serialName,com1);
                break;
        case 2: strcpy(serialName,com2);
                break;
        default: cout << "Error! valid ports are 1, 2, 3 and 4. "
                      << "Will try to open port 1." << endl;
    }

    try{
        tty_fd = open(serialName, O_RDWR);
        if(tty_fd == -1){
            throw 0;
        }
        cout << "Serial port in use: " << serialName << endl << endl;
        fcntl(tty_fd, F_SETFL, 0);
    }
    catch(...){
        std::cerr << "Error opening " << serialName<<endl;
        return 1;
    }
       

    // Program serial port to 115200, 8, 1, no parity
    //
    // Get the current options for the port
    tcgetattr(tty_fd, &options);

    // Set the baud rate to B115200 - 115200 or B9600 - 9600
    cfsetispeed(&options, B115200);
    cfsetospeed(&options, B115200);

    // Enable the receiver and set local mode
    options.c_cflag |= (CLOCAL | CREAD);

    // Setting parity checking (no parity) 8N1
    options.c_cflag &= ~PARENB;        /* no parity */
    options.c_cflag &= ~CSTOPB;        /* 1 stop bit */
    options.c_cflag &= ~CSIZE;         /* Mask the character size bits */
    options.c_cflag |= CS8;            /* Select 8 data bits */

    // Setting raw input
    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);

    // Setting raw output
    options.c_oflag &= ~OPOST;
    
    // Set the new options for the port
    tcsetattr(tty_fd, TCSANOW, &options);

    tcflush(tty_fd,TCIOFLUSH);
}

//send serial data
template <class TCont, class TSup>
void DataCommunicationLinux<TCont, TSup>::sendData(){
    unsigned char initChar = LOG_INIT_EVENT_TRANSMISSION; //this char will be received by Controller and its will send events log
    if (tty_fd == -1)
        cout << "Erro: the serial port is closed. Please, "
             << "use the openSerial() method to open it. " << endl;
    else{
        int n = write(tty_fd, &initChar, 1);  // send 1 bytes command advice heater controller to send event log
        if (n < 0){
            cout << "Error! write() command and motor bytes failed." << endl;
        }
    }
}

//read serial data
template <class TCont, class TSup>
int DataCommunicationLinux<TCont, TSup>::readData(TCont* id, TCont* y, TCont* mo, TCont* d, TCont* h, TCont* mi, TCont* s, TCont* pm, TCont* eT, TCont* cT){
    unsigned char buf[12];
    TSup res;
    if (tty_fd == -1)
        cout << "Erro: the serial port is closed. Please, "
             << "use the openSerial() method to open it. " << endl;
    else{
        res = read(tty_fd,buf,12);  //get serial data send over UART protocol by Controller
        if(((TCont)buf[11] != LOG_END_EVENT_LIST) && ((TCont)buf[0] == LOG_HEADING) && ((TCont)buf[11] == LOG_END_EVENT_TRANSMISSION)){ //verify header and trailer to guarantee correct and valid data
                                    
                                    // buf[0] = LOG_HEADING
            *id = (TCont)buf[1];   // buf[1] = DEVICE_ID_LOG
            *y  = (TCont)buf[2];   // buf[2] = year
            *mo = (TCont)buf[3];   // buf[3] = month
            *d  = (TCont)buf[4];   // buf[4] = day
            *h  = (TCont)buf[5];   // buf[5] = hour
            *mi = (TCont)buf[6];   // buf[6] = min
            *s  = (TCont)buf[7];   // buf[7] = seg
            *pm = (TCont)buf[8];   // buf[8] = pm
            *eT = (TCont)buf[9];   // buf[9] = eventType
            *cT = (TCont)buf[10];  // buf[10] = configType
                                    // buf[11] = LOG_END_EVENT_TRANSMISSION
            printf("\nDEBUG DataCommunicationLinux : Entrei readData: %u - %u:%u:%u:%u:%u:%u:%u:%u:%u",(TCont)buf[1], (TCont)buf[2], (TCont)buf[3], (TCont)buf[4], (TCont)buf[5], (TCont)buf[6],
                                                                                                         (TCont)buf[7], (TCont)buf[8], (TCont)buf[9], (TCont)buf[10]);
            return 0; //have data to collet yet
        }else{
            return 1; //end list
        }
   
    }
}


//close serial port of Linux
template <class TCont, class TSup>
void DataCommunicationLinux<TCont, TSup>::closeSerial(){
    tcflush(tty_fd,TCIOFLUSH);
    close(tty_fd);
}

#endif