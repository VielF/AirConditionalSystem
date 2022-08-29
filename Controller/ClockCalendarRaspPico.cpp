/*   File ClockCalendar.cpp

     Felipe Viel 

     Programa de Pós-Graduação em Engenharia Elétrica, CTC, UFSC

     Fevereiro de 2021.

Descricao: Definicao das funcoes membro para os "headers" declarados na classe ClockCalendar

*/

#ifndef CLOCKCALENDARRASPPICO_CPP
#define CLOCKCALENDARRASPPICO_CPP

#include <iostream>
#include <stdio.h>

#include "ClockCalendar.cpp"
#include "libConfig.h"

#include "hardware/rtc.h"
#include "pico/stdlib.h"
#include "pico/util/datetime.h"

using namespace std;

class ClockCalendarRaspPico : public ClockCalendar{
    private:
        datetime_t t;
   
    public:
        ClockCalendarRaspPico(){
            t.year  = YEAR_NUMBER_DEFAULT;
            t.month = MONTH_NUMBER_DEFAULT;
            t.day   = DAY_NUMBER_DEFAULT;
            t.dotw  = DAY_NAME_DEFAULT; // 0 is Sunday, so 5 is Friday
            t.hour  = HOUR_DEFAULT;
            t.min   = MIN_DEFAULT;
            t.sec   = SEG_DEFAULT;

            rtc_init();
            rtc_set_datetime(&t);

        }
        //parameters mo - month, d_number - number of day, d_name - number that represent day's name, y - year
        //           h - hour, mi - minute, int s - second
        virtual void setCalendar (int mo, int d_number, int d_name, int y, int h, int mi, int s){
            t.year  = y;
            t.month = mo;
            t.day   = d_number;
            t.dotw  = d_name; // 0 is Sunday, so 5 is Friday
            t.hour  = h;
            t.min   = mi;
            t.sec   = s;

            rtc_set_datetime(&t);
        }

        //parameters mo - month, d_number - number of day, d_name - number that represent day's name, y - year
        //           h - hour, mi - minute, int s - second
        virtual void readCalendar (uint8_t* m, uint8_t* d_number, uint8_t* d_name, uint8_t* y, uint8_t* h, uint8_t* mi, uint8_t* s){
            rtc_get_datetime(&t);

            *y = (uint8_t)(t.year%1000); //get the mod of year, ex: 2021 will return 21
            *m = (uint8_t)t.month;
            *d_number = (uint8_t)t.day;
            *d_name = (uint8_t)t.dotw;
            *h = (uint8_t)t.hour;
            *mi = (uint8_t)t.min;
            *s =  (uint8_t)t.sec;
        }
};

#endif