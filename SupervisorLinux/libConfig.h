#ifndef LIBCONFIG_H
#define LIBCONFIG_H

/*
Configuration of display follow the sequence - g f e d c b a
*/

#define DEBUG_MODE_PRINCIPAL 1
//#define DEBUG_MODE_ALL 1

#define COMMON_CATHODE 1

#define DAY_NAME_DEFAULT       5 // 0 - Sunday, 1 - Monday, 2 - Tuesday, 3 - wednesday, 4 - thursday, 5 - friday, 6 - saturday
#define DAY_NUMBER_DEFAULT     1
#define MONTH_NUMBER_DEFAULT   1
#define YEAR_NUMBER_DEFAULT 2021

#define HOUR_DEFAULT 0
#define MIN_DEFAULT  0

#ifdef DEBUG_MODE_ALL
#define SEG_DEFAULT 30
#else
#define SEG_DEFAULT 0
#endif

#ifdef COMMON_CATHODE

#define NUMBER_0 0x3F // 0x3F: 011 1111 
#define NUMBER_1 0x06 // 0x06: 000 0110 
#define NUMBER_2 0x5B // 0x5B: 101 1011 
#define NUMBER_3 0x4F // 0x4F: 100 1111 
#define NUMBER_4 0x66 // 0x66: 110 0110 
#define NUMBER_5 0x6D // 0x6D: 110 1101 
#define NUMBER_6 0x7C // 0x7C: 111 1100 
#define NUMBER_7 0x07 // 0x07: 000 0111 
#define NUMBER_8 0x7F // 0x7F: 111 1111 
#define NUMBER_9 0x67 // 0x67: 110 0111 

#else

#define NUMBER_0 0x40 // 0x40 100 0000
#define NUMBER_1 0x79 // 0x79 111 1001
#define NUMBER_2 0x24 // 0x24 010 0100
#define NUMBER_3 0x30 // 0x30 011 0000
#define NUMBER_4 0x19 // 0x19 001 1001
#define NUMBER_5 0x12 // 0x12 001 0010
#define NUMBER_6 0x03 // 0x03 000 0011
#define NUMBER_7 0x78 // 0x78 111 1000
#define NUMBER_8 0x00 // 0x00 000 0000
#define NUMBER_9 0x18 // 0x18 001 1000

#endif

//const int32_t numbers7Seg[10] ={NUMBER_0, NUMBER_1, NUMBER_2, NUMBER_3, NUMBER_4, NUMBER_5, NUMBER_6, NUMBER_7, NUMBER_8, NUMBER_9};


/*
DEFINES FOR GPIO PINS ID
*/

#define GPIO_7SEG_A 4
#define GPIO_7SEG_B 5
#define GPIO_7SEG_C 6
#define GPIO_7SEG_D 7
#define GPIO_7SEG_E 8
#define GPIO_7SEG_F 9
#define GPIO_7SEG_G 10


#define GPIO_7SEG_HOUR_EN  11
#define GPIO_7SEG_MIN_D_EN 12
#define GPIO_7SEG_MIN_U_EN 13
#define GPIO_7SEG_SEC_D_EN 14
#define GPIO_7SEG_SEC_U_EN 15

#define GPIO_LED         0
#define GPIO_BUZ         3
#define GPIO_RL_HEATER  21
#define GPIO_RL_MOTORB  22

#define GPIO_BUTTON_START 1
#define GPIO_BUTTON_CONF  2
#define GPIO_POT         26


#define GPIO_PIN_ENABLE  1
#define GPIO_PIN_DISABLE 0

#define UART_TX_PIN 16
#define UART_RX_PIN 17

#define UART_ID   uart0
#define BAUD_RATE 115200
#define DATA_BITS 8
#define STOP_BITS 1
#define PARITY    UART_PARITY_NONE

#define DEVICE_ID_LOG 1

#define LOG_EVENT_TURN_ON_AIR       0x44 //DEVICE CONTRO 1 - ASCII
#define LOG_EVENT_TURN_OFF_AIR      0x45 //DEVICE CONTRO 1 - ASCII
#define LOG_EVENT_DOOR_OPEN         0x32 //DEVICE CONTRO 1 - ASCII
#define LOG_EVENT_WINDOW_OPEN       0x33 //indicate that use 15 minutes in counter system
#define LOG_EVENT_DOOR_WINDOW_OPEN  0x34 //indicate that use 30 minutes in counter system
#define LOG_EVENT_DOOR_CLOSE        0x35 //DEVICE CONTRO 1 - ASCII
#define LOG_EVENT_WINDOW_CLOSE      0x36 //indicate that use 15 minutes in counter system
#define LOG_EVENT_DOOR_WINDOW_CLOSE 0x37 //indicate that use 30 minutes in counter system
#define LOG_HEADING                 0x46 // SOH - ASCII
#define LOG_INIT_EVENT_TRANSMISSION 0x47 // STX - ASCII
#define LOG_END_EVENT_TRANSMISSION  0x48 // ETX - ASCII
#define LOG_END_EVENT_LIST          0x49 // EOT - ASCII

//enum stateControl {stInit=0, stConfigure, stCount, stTurnon, stTurnoff, stShow, stIdle, stLed, stSound};

enum stateControlSupervisor {stInit=0, stReadData, stDisplayData};

#endif