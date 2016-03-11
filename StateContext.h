#ifndef StateContext_h
#define StateContext_h

#include <vector>

#include "State.h"

class State;
class GarageDoorOpener;

class StateContext {

 public:

    void transition(char);
	StateContext(State);

    //State getActiveState();

    State ActiveState;

    GarageDoorOpener *myGarageDoorOpener;
};

#endif // StateContext_h
