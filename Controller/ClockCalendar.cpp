/*   File ClockCalendar.h

     Felipe Viel 

     Programa de Pós-Graduação em Engenharia Elétrica, CTC, UFSC

     Fevereiro de 2021.

Descricao: Definicao das funcoes membro para os "headers" declarados na classe ClockCalendar para usar com RTC

*/
#ifndef CLOCKCALENDAR_H
#define CLOCKCALENDAR_H

#include <iostream>

using namespace std;

class ClockCalendar{
   
   public:
      ClockCalendar(){}
      //parameters mo - month, d_number - number of day, d_name - number that represent day's name, y - year
      //           h - hour, mi - minute, int s - second
      virtual void setCalendar (int mo, int d_number, int d_name, int y, int h, int mi, int s);

      //parameters mo - month, d_number - number of day, d_name - number that represent day's name, y - year
      //           h - hour, mi - minute, int s - second
      virtual void readCalendar (uint8_t* m, uint8_t* d_number, uint8_t* d_name, uint8_t* y, uint8_t* h, uint8_t* mi, uint8_t* s);
};

#endif