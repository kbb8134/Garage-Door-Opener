#include "StateContext.h"


StateContext::StateContext(State start){
	ActiveState = start;
}

void StateContext::transition(char event)
{
	//Overcurrent
	if(event == 'O'){
		if(this->ActiveState.tOvercurrent() != 0){
			this->ActiveState.Exit();
			this->ActiveState = ActiveState.tOvercurrent();
			this->ActiveState.Entry();
			TRANSITIONED = TRUE;
		}
	}
	//Beam Interrupt
	if(event == 'I'){
		if(this->ActiveState.tBeam() != 0){
			this->ActiveState.Exit();
			this->ActiveState = ActiveState.tBeam();
			this->ActiveState.Entry();
			TRANSITIONED = TRUE;
		}
	}
	//Button Press
	if(event == 'P'){
		if(this->ActiveState.tButton() != 0){
			this->ActiveState.Exit();
			this->ActiveState = ActiveState.tButton();
			this->ActiveState.Entry();
			TRANSITIONED = TRUE;
		}
	}
	//Door closed
	if(event == 'F'){
		if(this->ActiveState.tFinished() != 0){
			this->ActiveState.Exit();
			this->ActiveState = ActiveState.tFinished();
			this->ActiveState.Entry();
			TRANSITIONED = TRUE;
		}
	}
}

/*
State StateContext::getActiveState()
{
	return(this->ActiveState);
}
*/