#ifndef IOCONTROLRASPPICO_H
#define IOCONTROLRASPPICO_H

#include <iostream>
#include "libConfig.h"
#include "IOControl.cpp"
#include "ClockCalendarRaspPico.cpp"

#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/uart.h"

using namespace std;

class IOControlRaspPico : public IOControl {
   private:
       ClockCalendarRaspPico timeEvents;
   
   public:
      IOControlRaspPico() {}
      int getSensorsStauts();
      void setPinsOut(int numPin, int state);
      void setEnableAir();
      void setDisableAir();
      bool getButtonIn();
      void initIO();

      //serial communication and FIFO structure control
      void dataLogSend();
      void setEventLog(uint8_t event, uint8_t configType);
};


#endif
