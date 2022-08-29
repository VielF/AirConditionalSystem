#ifndef CONTROLRASPPICO_CPP
#define CONTROLRASPPICO_CPP

#include <iostream>
#include "IOControlRaspPico.h"
#include "libConfig.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"


using namespace std;

class ControlRaspPico{
   private:
      IOControlRaspPico      ioControl;
      stateControl           st = stInit;

   public:
      ControlRaspPico(){};
      void Control(){
         while(1){
            switch(st){
               //Init the sistems and all pins
               case stInit:   

#ifdef DEBUG_MODE_PRINCIPAL
                              sleep_ms(5000);
                              printf("\nDEBUG ControlRaspPico : Entrei Init State");
#endif               
                              ioControl.initIO();
                              st = stAirDisable;
                              break;

               //verify every time if Start button was pressed
               case stAirDisable:  
#ifdef DEBUG_MODE_ALL
                                 printf("\nDEBUG ControlRaspPico : Entrei stAirDisable");
#endif                           
                                 if(TWO_SENSORS_DESAVTIVATE == ioControl.getSensorsStauts()){ 
                                    ioControl.setPinsOut(GPIO_LED, GPIO_PIN_DISABLE);
                                 }else{
                                    ioControl.setPinsOut(GPIO_LED, GPIO_PIN_ENABLE);
                                 }
                                 ioControl.getButtonIn();                //verify the buttons pressed
                                 ioControl.dataLogSend();
                                 if(ioControl.getStartStatus()){         //if was start and door and window closed
#ifdef DEBUG_MODE_PRINCIPAL
                                    printf("\nDEBUG ControlRaspPico : Entrei stAirDisable - Opening Source power: going to enable mode ");
#endif                                    
                                    st = stAirEnable;
                                    ioControl.setOffStartStatus();
                                    
                                 }else{                                  //else continue in configure
                                    st = stAirDisable;
                                 }
                                 break;

               //verify every time if some port or window was open
               case stAirEnable:     
#ifdef DEBUG_MODE_ALL
                                 printf("\nDEBUG ControlRaspPico : Entrei stAirEnable");
#endif                           
                                 ioControl.dataLogSend();
                                 //ioControl.getButtonIn();
                                 if(ONE_OR_TWO_SENSORS_ACTIVATE == ioControl.getSensorsStauts()){  //veify if door or windows was open
                                    ioControl.setEventLog(LOG_EVENT_TURN_OFF_AIR,0); //set start event
#ifdef DEBUG_MODE_PRINCIPAL                                    
                                    printf("\nDEBUG ControlRaspPico : stAirEnable - door or windows was open: going to disable mode");
#endif 
                                    st = stAirDisable;
                                    ioControl.setOffStartStatus();
                                    ioControl.setPinsOut(GPIO_LED, GPIO_PIN_ENABLE);
                                    ioControl.setDisableAir();
                                    ioControl.setIORelayStatus(GPIO_PIN_DISABLE);
                                 }else{
                                    st = stAirEnable;
                                 }
                                 break;
                                 
            
               default: st = stInit;   //default state go every to init state
                        break;
            }
         }
   }

};

#endif