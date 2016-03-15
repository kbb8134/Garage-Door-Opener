#include "GarageDoorOpener.h"
#include <stdio.h>

// GarageDoorOpener constructor
GarageDoorOpener::GarageDoorOpener()
{
	receivedInput = 'x'; // Initialized to default
	event = 'x';

	motorDown = false;
	motorUp = false;
	beamOn = false;
	count = 0;
	

    // create state objects here
	Closed ClosedState(this);
	Closing ClosingState(this);
	Open OpenState(this);
	Opening OpeningState(this);
	StoppedClosing SCState(this);
	StoppedOpening SOState(this);
	
	//Overcurrent, interrupt, button, finished
	ClosedState.setTransitions(0, 0 , OpeningState, 0);
	ClosingState.setTransitions(OpeningState, OpeningState, SCState, ClosedState);
	OpenState.setTransitions(0, 0, ClosingState, 0);
	OpeningState.setTransitions(SOState, 0, SOState, OpenState);
	SCState.setTransitions(0, 0, OpeningState, 0);
	SOState.setTransitions(0, 0, ClosingState, 0);

    //StateContext myStateContext(ClosedState);

	// create the inputscanner thread
	pthread_attr_t threadAttr;
	pthread_attr_init(&threadAttr);		// initialize thread attributes structure
	pthread_attr_setdetachstate(&threadAttr, PTHREAD_CREATE_JOINABLE);
	pthread_create(&GDOThreadID, &threadAttr, &GarageDoorOpener::DoorThread, this);


	// create the inputscanner thread
	pthread_create(&inputScannerThreadID, &threadAttr, &InputScanner::InputScannerThread, &myInputScanner);

}

// GarageDoorOpener destructor
GarageDoorOpener::~GarageDoorOpener()
{
	// input scanner will join when GDO object is no longer available
	pthread_join(inputScannerThreadID, NULL);

	// What else should go here?
}

void GarageDoorOpener::setmotorDown(bool arg)
{
	motorDown = arg;
}

void GarageDoorOpener::setmotorUp(bool arg)
{
	motorUp = arg;
}

void GarageDoorOpener::setBeam(bool arg)
{
	beamOn = arg;
}

// Thread to be called when Door is opening or closing
void* GarageDoorOpener::DoorThread(void* param)
{
	while(1){
		//Printing the countdown if the door is moving
		if(((GarageDoorOpener*)param)->motorDown || ((GarageDoorOpener*)param)->motorUp){
			printf("%d\n", ((GarageDoorOpener*)param)->count);
		}
		//Garage door has fully closed or opened
		if(((GarageDoorOpener*)param)->count == 10 && (((GarageDoorOpener*)param)->motorUp || ((GarageDoorOpener*)param)->motorDown)){
			((GarageDoorOpener*)param)->myStateContext.transition('F');
			((GarageDoorOpener*)param)->count = 0;
			continue;
		}
		//Looking for messages from inputscanner
		if(MUTEX == false){
			MUTEX = true;
			if(OVERCURRENT == true){
				((GarageDoorOpener*)param)->myStateContext.transition('O');
			}
			if(BUTTON == true){
				((GarageDoorOpener*)param)->myStateContext.transition('P');
			}
			if(INTERRUPT == true && ((GarageDoorOpener*)param)->beamOn){
				((GarageDoorOpener*)param)->myStateContext.transition('I');
			}
			MUTEX = false;
			if(TRANSITIONED){
				((GarageDoorOpener*)param)->count = 0;
				TRANSITIONED = false;
				continue;
			}
		}
		((GarageDoorOpener*)param)->count++;
		nanospin_ns(1E9);
	}
	return 0;
}
