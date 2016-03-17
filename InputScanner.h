#ifndef InputScanner_h
#define InputScanner_h

#include "GarageDoorOpener.h"

class InputScanner
{

 public:

    static void* InputScannerThread(void* arg);
    void alertOvercurrent();
    void alertbeam();
    void alertbutton();


    //GarageDoorOpener *myGarageDoorOpener;
};

#endif // InputScanner_h
