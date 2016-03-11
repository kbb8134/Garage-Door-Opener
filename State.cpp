#include "State.h"

State::State(GarageDoorOpener* door){
	reciever = door;
}

void State::Entry()
{

}


void State::Exit()
{

}

State State::tOvercurrent()
{
	return(this->Overcurrent);
}

State State::tBeam()
{
	return(this->Beam);
}

State State::tButton()
{
	return(this->Button);
}

State State::tFinished()
{
	return(this->Finished);
}

void State::setTransitions(State OC, State I, State B, State F)
{
	this->Overcurrent = OC;
	this->Beam = I;
	this->Button = B;
	this->Finished = F;
}

