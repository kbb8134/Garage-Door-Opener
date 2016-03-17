#ifndef StateContext_h
#define StateContext_h

#include "State.h"
//#include "GarageDoorOpener.h"
//#include "Globals.h"
//class GarageDoorOpener;

class StateContext {

 public:
	// Attributes
    void* ActiveState;
    //GarageDoorOpener* myGarageDoorOpener;

    // Methods
    StateContext(void*);
    void transition(char);
    //State getActiveState();

};

#endif // StateContext_h
