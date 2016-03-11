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

    //
	InputScanner myInputScanner;
    StateContext myStateContext(ClosedState);

	// create the inputscanner thread
	pthread_attr_t threadAttr;
	pthread_attr_init(&threadAttr);		// initialize thread attributes structure
	pthread_attr_setdetachstate(&threadAttr, PTHREAD_CREATE_JOINABLE);
	pthread_create(&inputScannerThreadID, &threadAttr, &InputScanner::InputScannerThread, &myInputScanner);

}

// GarageDoorOpener destructor
GarageDoorOpener::~GarageDoorOpener()
{
	// input scanner will join when GDO object is no longer available
	pthread_join(inputScannerThreadID, NULL);

	// What else should go here?
}

void setmotorDown(bool arg)
{
	motorDown = arg;
}

void setmotorUp(bool arg)
{
	motorUp = arg;
}

void setBeam(bool arg)
{
	beamOn = arg;
}

void* DoorThread(void* param)
{
	while(1){
		//Printing the countdown if the door is moving
		if(motorDown || motorUp){
			printf("%d\n", count);
		}
		//Garage door has fully closed or opened
		if(count == 10 && (motorUp || motorDown)){
			myStateContext.transition('F');
			count = 0;
			continue;
		}
		//Looking for messages from inputscanner
		if(MUTEX == false){
			MUTEX = true;
			if(OVERCURRENT = true){
				myStateContext.transition('O');
			}
			if(BUTTON = true){
				myStateContext.transition('P');
			}
			if(INTERRUPT = true && beamON){
				myStateContext.transition('I');
			}
			MUTEX = false;
			if(TRANSITIONED){
				count = 0;
				TRANSITIONED = false;
				continue;
			}
		}
		count++;
		nanospin_ns(1E9);
	}
	return 0;
}