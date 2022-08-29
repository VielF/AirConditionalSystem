cmake_minimum_required(VERSION 3.19)

add_executable(controlAir libConfig.h testControler.cpp ControlRaspPico.cpp IOControl.cpp ClockCalendar.cpp ClockCalendarRaspPico.cpp NodeRaspPico.h NodeRaspPico.cpp ListRaspPico.h ListRaspPico.cpp IOControlRaspPico.h IOControlRaspPico.cpp)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(controlAir)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "-Wall")

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()
   
# enable usb output, disable uart output
pico_enable_stdio_usb(controlAir 1)
pico_enable_stdio_uart(controlAir 0)

# Pull in our pico_stdlib which aggregates commonly used features
target_link_libraries(controlAir pico_stdlib hardware_uart hardware_rtc)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(controlAir)
