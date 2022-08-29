#include <jni.h>
#include <string>
#include "ControlSupervisor.cpp"

//create a C++ object to be manipulate during APP execution and return as object pointer
extern "C" JNIEXPORT jlong JNICALL
Java_com_example_supervisorandroid_1v2_MainActivity_createControl(
        JNIEnv* env,
        jobject thiz) {

    return (long)(new ControlSupervisor());
}

//emulate connection to read data from controller
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_supervisorandroid_1v2_MainActivity_connect(
        JNIEnv* env,
        jobject thiz, jlong numberptr) {
    std::string stringToPrint;
    ControlSupervisor* control = reinterpret_cast<ControlSupervisor *>(numberptr); //here we create a new C++ ControllerSupervisor object pointer and point to real object Create in the APP start
    stringToPrint = control->readData(); //call the method readData
    return env->NewStringUTF(stringToPrint.c_str()); //return the string result
}
//to use display all events method
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_supervisorandroid_1v2_MainActivity_displayAll(
        JNIEnv* env,
        jobject thiz, jlong numberptr) {

    std::string stringToPrint;
    ControlSupervisor* control = reinterpret_cast<ControlSupervisor *>(numberptr); //here we create a new C++ ControllerSupervisor object pointer and point to real object Create in the APP start
    stringToPrint = control->displayData(1,0,0,0,0); //call the method displayData
    return env->NewStringUTF(stringToPrint.c_str());  //return the string result
}

//to use Count Hour that Air-conditioner was on
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_supervisorandroid_1v2_MainActivity_countHour(
        JNIEnv* env,
        jobject thiz, jlong numberptr, jint start, jint end, jboolean month, jint monthNumber) {
    std::string stringToPrint;

    ControlSupervisor* control = reinterpret_cast<ControlSupervisor *>(numberptr); //here we create a new C++ ControllerSupervisor object pointer and point to real object Create in the APP start

    if(month == JNI_TRUE) { //decide if count by month or by days interval
        stringToPrint = control->displayData(3,start, end, 1, monthNumber); //call count time by month interval
    }else{
        stringToPrint = control->displayData(3,start, end, 0, monthNumber); //call count time by days interval
    }


    return env->NewStringUTF(stringToPrint.c_str()); //return the string result
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_supervisorandroid_1v2_MainActivity_listDate(
        JNIEnv* env,
        jobject thiz, jlong numberptr, jint start, jint end, jboolean month, jint monthNumber) {
    std::string stringToPrint;

    ControlSupervisor* control = reinterpret_cast<ControlSupervisor *>(numberptr); //here we create a new C++ ControllerSupervisor object pointer and point to real object Create in the APP start

    if(month == JNI_TRUE) { //decide if list by month or by days interval
        stringToPrint = control->displayData(2,start, end, 1, monthNumber); //call list event by month interval
    }else{
        stringToPrint = control->displayData(2,start, end, 0, monthNumber); //call list event by days interval
    }


    return env->NewStringUTF(stringToPrint.c_str());
}

/*
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_supervisorandroid_1v2_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject thiz) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
*/

//emulate data reading list from controller to be used in other functions
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_supervisorandroid_1v2_MainActivity_emulateComm(
        JNIEnv* env,
        jobject thiz, jlong numberptr) {

    std::string stringToPrint;

    ControlSupervisor* control = reinterpret_cast<ControlSupervisor *>(numberptr); //here we create a new C++ ControllerSupervisor object pointer and point to real object Create in the APP start

    stringToPrint = control->displayData(5,0,0,0,0); //call emulate function

    return env->NewStringUTF(stringToPrint.c_str()); //return a string but is not used
}

