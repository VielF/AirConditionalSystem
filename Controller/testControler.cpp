

#include <iostream>
#include "libConfig.h"
#include "ControlRaspPico.cpp"
#include "pico/stdlib.h"

using namespace std;

int main(){
   stdio_init_all();

#ifdef DEBUG_MODE_PRINCIPAL
      sleep_ms(5000);
      printf("\nIniciando sistema ...");
      sleep_ms(3000);
      printf("\nSistema estabilizando .....");
#endif

   ControlRaspPico control;

   control.Control();
}