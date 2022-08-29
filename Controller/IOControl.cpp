#ifndef IOCONTROL_CPP
#define IOCONTROL_CPP

#include <iostream>
#include "libConfig.h"
#include "ListRaspPico.h"

using namespace std;

class IOControl{
   protected:
      int releAirCondition;
      int sensorDoor;
      int sensorWindow;
      int startButton;
      ListRaspPico fifo_events;
      int sizeList;
      uint8_t eventTime;
      
   public:
      IOControl() : releAirCondition(GPIO_PIN_DISABLE), sensorDoor(GPIO_PIN_DISABLE), sensorWindow(GPIO_PIN_DISABLE), startButton(0), sizeList(0) {}
      void setIORelayStatus(int status){
#ifdef DEBUG_MODE_ALL
         printf("\nEntrei setIORelayStatus");
#endif         
            releAirCondition = status;
      }

      bool getIOStatus(int typeIO){
#ifdef DEBUG_MODE
         printf("\nEntrei getIOStatus");
#endif         
         if(GPIO_RL_AIR == typeIO){
            if(releAirCondition == 1){ return true;      
            }else{ return false;} 
         }
      }

      void setOffStartStatus(){
         startButton = 0;
      }

      int getStartStatus(){
         return startButton;
      }
      
      virtual void setPinsOut(int numPin, int state) = 0;
      virtual bool getButtonIn() = 0;
      virtual void initIO() = 0;
      virtual int getSensorsStauts() = 0;
      virtual void setEnableAir() = 0;
      virtual void setDisableAir() = 0;
      virtual void dataLogSend() = 0;
      virtual void setEventLog(uint8_t event, uint8_t configType) = 0;
};


#endif
