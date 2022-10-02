#include "FirstClassESP.h"

using namespace std;

void FirstClassESP::runMethod(int i){
    cout << "Hello World from C++ "<< i << '\n';
    vTaskDelay(pdMS_TO_TICKS(1000));
}