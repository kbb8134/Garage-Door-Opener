#ifndef GarageDoorOpener_h
#define GarageDoorOpener_h

#include <iostream>
#include <ctype.h>
#include <string>
#include <iomanip>

// QNX Libraries
#include <pthread.h>      // pthread function calls
#include <sys/neutrino.h>
#include <sys/netmgr.h>
#include <sys/syspage.h>  // SYSPAGE_ENTRY() function
#include <time.h>
#include <unistd.h>       // for sleep()
#include <stdint.h>       // for uintptr_t
#include <hw/inout.h>     // for in*() and out*() functions
#include <sys/mman.h>     // for mmap_device_io()
#include <inttypes.h>     // for ClockCycles() return value

#include "State.h"
#include "Globals.h"
//#include "InputScanner.h"
#include "StateContext.h"

class InputScanner;
class StateContext;

class GarageDoorOpener {

 public:
	static char receivedInput;
	static char event;
	pthread_t GDOThreadID;
	//pthread_t inputScannerThreadID;
//	InputScanner* myInputScanner;
    StateContext* myStateContext;

    GarageDoorOpener();		// constructor
    ~GarageDoorOpener();	// destructor
 //   void setmotorDown(bool);
//    void setmotorUp(bool);
//    void setBeam(bool);
    void* DoorThread(void*);
    
 //private:
	int count;
 //   bool motorDown;
 //   bool motorUp;
 //   bool beamOn;
};

#endif // GarageDoorOpener_h
