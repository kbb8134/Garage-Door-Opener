#ifndef State_h
#define State_h
#include "Globals.h"
#include <iostream>

//#include "GarageDoorOpener.h"
//class GarageDoorOpener;

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

		void* reciever;
		State* eOvercurrent;
		State* Beam;
		State* Button;
		State* Finished;
};

class Closed : public State{
	public:
		void Entry();
		void Exit();
};

class Closing : public State {
	public:
		void Entry();
		void Exit();
};

class Open : public State {
	public:
		void Entry();
		void Exit();
};

class Opening : public State {
	public:
		void Entry();
		void Exit();
};

class StoppedClosing : public State {
	public:
		void Entry();
		void Exit();

};

class StoppedOpening : public State {
	public:
		void Entry();
		void Exit();
};

#endif // State_h
