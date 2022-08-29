#ifndef IOCONTROLRASPPICO_CPP
#define IOCONTROLRASPPICO_CPP

#include <iostream>
#include "libConfig.h"
#include "IOControlRaspPico.h"

using namespace std;

//set any general pins (GPIO) to 1 (ENABLE) or to 0 (DISABLE)
void IOControlRaspPico::setPinsOut(int numPin, int state){
#ifdef DEBUG_MODE
   printf("\nDEBUG IOControlRaspPico : Entrei setPinsOut");
#endif         
   gpio_put(numPin, state);
}

//get the potentiometer value
int IOControlRaspPico::getSensorsStauts(){
#ifdef DEBUG_MODE_ALL
   printf("\nDEBUG IOControlRaspPico : Entrei getSensorsStauts");
#endif   

   if((gpio_get(GPIO_SENSOR_DOOR) == 1)){

#ifdef DEBUG_MODE_PRINCIPAL //used to emulate sensor with button
      sleep_ms(500); //debounce
#endif

      if((this->sensorDoor == GPIO_PIN_DISABLE) && (gpio_get(GPIO_SENSOR_DOOR) == 1)){
         this->sensorDoor = GPIO_PIN_ENABLE;
         setEventLog(LOG_EVENT_DOOR_OPEN, 0);
#ifdef DEBUG_MODE_PRINCIPAL 
         printf("\nDEBUG IOControlRaspPico : Entrei getSensorsStauts: DOOR change: close->open");
#endif
      }
   }else{
      if((this->sensorDoor == GPIO_PIN_ENABLE) && (gpio_get(GPIO_SENSOR_DOOR) == 0)){
         this->sensorDoor = GPIO_PIN_DISABLE;
         setEventLog(LOG_EVENT_DOOR_CLOSE, 0);
#ifdef DEBUG_MODE_PRINCIPAL 
         printf("\nDEBUG IOControlRaspPico : Entrei getSensorsStauts: DOOR change: open->close");
#endif
      }
   }
   if((gpio_get(GPIO_SENSOR_WINDOW) == 1)){

#ifdef DEBUG_MODE_PRINCIPAL //used to emulate sensor with button
      sleep_ms(200); //debounce
#endif

      if((this->sensorWindow == GPIO_PIN_DISABLE) && (gpio_get(GPIO_SENSOR_WINDOW) == 1)){
         this->sensorWindow = GPIO_PIN_ENABLE;
         setEventLog(LOG_EVENT_WINDOW_OPEN, 0);
#ifdef DEBUG_MODE_PRINCIPAL 
         printf("\nDEBUG IOControlRaspPico : Entrei getSensorsStauts: WINDOW change: close->open");
#endif
      }
   }else{
      if((this->sensorWindow == GPIO_PIN_ENABLE) && (gpio_get(GPIO_SENSOR_WINDOW) == 0)){
         this->sensorWindow = GPIO_PIN_DISABLE;
         setEventLog(LOG_EVENT_WINDOW_CLOSE, 0);
#ifdef DEBUG_MODE_PRINCIPAL 
         printf("\nDEBUG IOControlRaspPico : Entrei getSensorsStauts: WINDOW change: open->close");
#endif
      }
   }

   if((gpio_get(GPIO_SENSOR_DOOR) == 1) || (gpio_get(GPIO_SENSOR_WINDOW) == 1)){
      return ONE_OR_TWO_SENSORS_ACTIVATE;
   }else{
      return TWO_SENSORS_DESAVTIVATE;
   }
      
}

void IOControlRaspPico::setEnableAir(){
   //Enable Air Relay
   setPinsOut(GPIO_LED, GPIO_PIN_DISABLE);
   sleep_ms(100);
   setPinsOut(GPIO_RL_AIR, GPIO_PIN_ENABLE);
}

void IOControlRaspPico::setDisableAir(){
   //Disable Air Relay
   setPinsOut(GPIO_LED, GPIO_PIN_ENABLE);
   sleep_ms(100);
   setPinsOut(GPIO_RL_AIR, GPIO_PIN_DISABLE);
}

//control Button function when pressed - Start/Pause and Config
bool IOControlRaspPico::getButtonIn(){
   int countPressed = 0;
   
#ifdef DEBUG_MODE_ALL 
   printf("\nDEBUG IOControlRaspPico : Entrei getButtonIn");
#endif

   if (gpio_get(GPIO_BUTTON_START)){
      while(gpio_get(GPIO_BUTTON_START));
      sleep_ms(100); //debounce

      if(ONE_OR_TWO_SENSORS_ACTIVATE == getSensorsStauts()){ 

#ifdef DEBUG_MODE_PRINCIPAL
            printf("\nDEBUG IOControlRaspPico : Entrei GPIO_BUTTON_START pressionado - há porta ou janela aberta");
#endif                

         //Port or window open (or both)
         setDisableAir();
         this->releAirCondition = GPIO_PIN_DISABLE;
         setEventLog(LOG_EVENT_TURN_OFF_AIR, 0); 
         this->startButton = 0;
         return false;

      }else{

#ifdef DEBUG_MODE_PRINCIPAL
         printf("\nDEBUG IOControlRaspPico : Entrei GPIO_BUTTON_START pressionado - não há porta ou janela aberta");
#endif                    

         //Port or window closed
         setEnableAir();
         this->startButton = 1;
         this->releAirCondition = GPIO_PIN_ENABLE;
         setEventLog(LOG_EVENT_TURN_ON_AIR, 0); 
         return true;
      }
   }
   
}


void IOControlRaspPico::initIO(){
   //init display pin as out
#ifdef DEBUG_MODE_PRINCIPAL
   printf("\nDEBUG IOControlRaspPico : Entrei initIO");
#endif
   
   //enable LED pin
   gpio_init(GPIO_LED);
   gpio_set_dir(GPIO_LED, GPIO_OUT);

   //enable Motor Relay pin
   gpio_init(GPIO_RL_AIR);
   gpio_set_dir(GPIO_RL_AIR, GPIO_OUT);


   //enable Start Button pin
   gpio_init(GPIO_BUTTON_START);
   gpio_set_dir(GPIO_BUTTON_START, GPIO_IN);

   //enable Sensor Port pin
   gpio_init(GPIO_SENSOR_DOOR);
   gpio_set_dir(GPIO_SENSOR_DOOR, GPIO_IN);

   //enable Sensor Window pin
   gpio_init(GPIO_SENSOR_WINDOW);
   gpio_set_dir(GPIO_SENSOR_WINDOW, GPIO_IN);

   //configure UART 0 on GPIOs pins 16 and 17 that use uart0 (multiplexed) to Supervisor Notbook
   //We also define the baud rate to 115.200 bps
   uart_init(UART_ID, BAUD_RATE);
   gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
   gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART); 
   uart_set_hw_flow(UART_ID, false, false); //Set UART flow control CTS/RTS, we don't want these, so turn them off
   uart_set_format (UART_ID, DATA_BITS, STOP_BITS, PARITY);

   //configure UART 1 on GPIOs pins 8 and 9 that use uart0 (multiplexed) to bluetooth module communication
   //We also define the baud rate to 9.600 bps
   uart_init(UART_ID_BT, BAUD_RATE_BT);
   gpio_set_function(UART_TX_BT_PIN, GPIO_FUNC_UART);
   gpio_set_function(UART_TX_BT_PIN, GPIO_FUNC_UART); 
   uart_set_hw_flow(UART_ID_BT, false, false); //Set UART flow control CTS/RTS, we don't want these, so turn them off
   uart_set_format (UART_ID_BT, DATA_BITS_BT, STOP_BITS_BT, PARITY_BT);

#ifdef DEBUG_MODE_ALL
   uart_puts(uart0, "UARTO init!\n");
#endif

   //to use UART 
   //Tx : uart_puts(uart0, "Hello world!"); or void uart_putc (uart_inst_t *uart,char c);
   //Rx : void uart_read_blocking (uart_inst_t *uart, uint8_t *dst, size_t len)  or char uart_getc (uart_inst_t *uart)
   //verify if have connection with supervisor : bool uart_is_readable (uart_inst_t *uart)
   //verify if can send data and buffer is not full: bool uart_is_writable (uart_inst_t *uart)

   //parameters mo - month, d_number - number of day, d_name - number that represent day's name, y - year
   //           h - hour, mi - minute, int s - second
   timeEvents.setCalendar(4,10,6,2021,13,30,0);
}

void IOControlRaspPico::dataLogSend(){
   uint8_t year;
   uint8_t month;
   uint8_t day;
   uint8_t hour;
   uint8_t min;
   uint8_t seg;
   uint8_t pm;
   uint8_t eventType;
   uint8_t configType;
   int size = sizeList;
   uint8_t initValue = 0x00;
   uint8_t initValue_BT = 0x00;
   uart_inst_t *uart_type;
   int endTwice = 0;
   if(uart_is_readable(UART_ID) || uart_is_readable(UART_ID_BT)){
      if(uart_is_readable(UART_ID)){
         initValue = (uint8_t)uart_getc(UART_ID);
      }
      if(uart_is_readable(UART_ID_BT)){
         initValue_BT = (uint8_t)uart_getc(UART_ID_BT);
      }
      
      
      if(LOG_INIT_EVENT_TRANSMISSION == initValue || LOG_INIT_EVENT_TRANSMISSION_SP == initValue_BT){
#ifdef DEBUG_MODE_PRINCIPAL
         printf("\nDEBUG IOControlRaspPico : Entrei dataLogSend\n");
#endif
         /* This point we choose between 
             uart 0 - to send data to notbook,
             uart 1 - to send data to bluetooth module and send to smartphone 
         */
         if(initValue_BT == LOG_INIT_EVENT_TRANSMISSION_SP){
            uart_type = UART_ID_BT;
         }else{
            uart_type = UART_ID;
         }

         for(int i = 1; i <= size ;i++){
            fifo_events.readFirst(&year, &month, &day, &hour, &min, &seg,&pm, &eventType,&configType);
#ifdef DEBUG_MODE_PRINCIPAL
               printf("\nDEBUG IOControlRaspPico : Entrei dataLogSend: %u:%u:%u:%u:%u:%u:%u:%u:%u",year,month,day,hour,min,seg,pm,eventType,configType);
#endif
            sleep_ms(100);
            uart_putc_raw(uart_type, ((char)LOG_HEADING));
            uart_putc_raw(uart_type, ((char)DEVICE_ID_LOG));
            uart_putc_raw(uart_type, ((char)year));
            uart_putc_raw(uart_type, ((char)month));
            uart_putc_raw(uart_type, ((char)day));
            uart_putc_raw(uart_type, ((char)hour));
            uart_putc_raw(uart_type, ((char)min));
            uart_putc_raw(uart_type, ((char)seg));
            uart_putc_raw(uart_type, ((char)pm));
            uart_putc_raw(uart_type, ((char)eventType));
            uart_putc_raw(uart_type, ((char)configType));
            uart_putc_raw(uart_type, ((char)LOG_END_EVENT_TRANSMISSION));

#ifdef DEBUG_MODE_ALL
            uart_putc(uart0, ((char)DEVICE_ID_LOG));
            uart_putc(uart0, ((char)LOG_HEADING));
            uart_putc(uart0, '1');
            uart_putc(uart0, '4');
            uart_putc(uart0, '5');
            uart_putc(uart0, '3');
            uart_putc(uart0, '1');
            uart_putc(uart0, 'D');
            uart_putc(uart0, '0');
            uart_putc(uart0, ((char)LOG_END_EVENT_TRANSMISSION));
#endif
            fifo_events.removeFirst();
            sizeList--;
         }
#ifdef DEBUG_MODE_PRINCIPAL
         printf("\nDEBUG IOControlRaspPico : Entrei dataLogSend: acabou os eventos");
#endif

         sleep_ms(100);
      
         uart_putc(uart_type, '0');
         uart_putc(uart_type, '0');
         uart_putc(uart_type, '0');
         uart_putc(uart_type, '0');
         uart_putc(uart_type, '0');
         uart_putc(uart_type, '0');
         uart_putc(uart_type, '0');
         uart_putc(uart_type, '0');
         uart_putc(uart_type, '0');
         uart_putc(uart_type, '0');
         uart_putc(uart_type, '0');
         uart_putc(uart_type, ((char)LOG_END_EVENT_LIST));
         
      }

   }
   
}

void IOControlRaspPico::setEventLog(uint8_t event, uint8_t configType){
   uint8_t m;
   uint8_t d_number;
   uint8_t d_name;
   uint8_t y;
   uint8_t h;
   uint8_t mi;
   uint8_t s;
   uint8_t pm = 0;

#ifdef DEBUG_MODE_PRINCIPAL
   printf("\nDEBUG IOControlRaspPico : Entrei setEventLog: %u:%u", event, configType);
#endif

   timeEvents.readCalendar(&m, &d_number, &d_name, &y, &h, &mi, &s);
   if(h > 11){
      pm = 1;
   }
   fifo_events.insertAfterLast(y, m, d_number, h, mi, s,pm, event, configType);
   sizeList++;
}

#endif
