#ifndef State_h
#define State_h
#include "GarageDoorOpener.h"

class GarageDoorOpener;

class State {

 public:

	//State(GarageDoorOpener*);
	
    virtual void Entry()=0;
    virtual void Exit()=0;

    // The following five functions represent transitions
    // Each state will know what state it should transistion in an event
    // If it does not tranistion during an event it returns NULL

    State* tOvercurrent();
    State* tBeam();
    State* tButton();
	// Finished represents the transition between the door moving and it completing a movement
    State* tFinished();
    void setTransitions(State*, State*, State*, State*);

 //protected:
    GarageDoorOpener *reciever;
    State* Overcurrent;
    State* Beam;
    State* Button;
    State* Finished;
};

class xxx : public State{};
#endif // State_h
