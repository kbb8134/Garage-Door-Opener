#ifndef InputScanner_h
#define InputScanner_h

//#include "GarageDoorOpener.h"
#include "Globals.h"
#include <pthread.h>
#include <iostream.h>
#include <unistd.h>

class InputScanner
{

 public:

	InputScanner();
	pthread_t inputScannerThreadID;
    static void* InputScannerThread(void* arg);
    void alertOvercurrent();
    void alertbeam();
    void alertbutton();


    //GarageDoorOpener *myGarageDoorOpener;
};

#endif // InputScanner_h
