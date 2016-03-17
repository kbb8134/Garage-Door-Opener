#include "StateContext.h"


StateContext::StateContext(void* start){
	ActiveState = (State*)start;
}

void StateContext::transition(char event)
{
	//Overcurrent
	if(event == 'O'){
		if(((State*)ActiveState)->tOvercurrent() != 0){
			((State*)ActiveState)->Exit();
			ActiveState = (void*)((State*)ActiveState)->tOvercurrent();
			((State*)ActiveState)->Entry();
			::TRANSITIONED = true;
		}
	}
	//Beam Interrupt
	if(event == 'I'){
		if(((State*)ActiveState)->tBeam() != 0){
			((State*)ActiveState)->Exit();
			ActiveState = (void*)((State*)ActiveState)->tBeam();
			((State*)ActiveState)->Entry();
			::TRANSITIONED = true;
		}
	}
	//Button Press
	if(event == 'P'){
		if(((State*)ActiveState)->tButton() != 0){
			((State*)ActiveState)->Exit();
			ActiveState = (void*)((State*)ActiveState)->tButton();
			((State*)ActiveState)->Entry();
			::TRANSITIONED = true;
		}
	}
	//Door closed
	if(event == 'F'){
		if(((State*)ActiveState)->tFinished() != 0){
			((State*)ActiveState)->Exit();
			ActiveState = (void*)((State*)ActiveState)->tFinished();
			((State*)ActiveState)->Entry();
			::TRANSITIONED = true;
		}
	}
}

/*
State StateContext::getActiveState()
{
	return(this->ActiveState);
}
*/
