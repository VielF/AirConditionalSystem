#include <stdio.h>
#include <iostream>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "FirstClassESP.h"

//você pode aplicar desta forma
/*
extern "C" {
   void app_main();
}
*/

//ou desta
extern "C" void app_main(void){
    FirstClassESP app;
    int i=0;

    while(true){
        app.runMethod(i);
        i++;
    }

}
