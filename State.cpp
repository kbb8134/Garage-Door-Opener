#include "State.h"

//State::State(GarageDoorOpener* door){
//	Receiver = door;
//}


State* State::tOvercurrent()
{
	return(this->eOvercurrent);
}

State* State::tBeam()
{
	return(this->Beam);
}

State* State::tButton()
{
	return(this->Button);
}

State* State::tFinished()
{
	return(this->Finished);
}

void State::setTransitions(State* OC, State* I, State* B, State* F)
{
	this->eOvercurrent = OC;
	this->Beam = I;
	this->Button = B;
	this->Finished = F;
}


void Closed::Entry(){
	std::cout << "Garage Door Closed. Beam off\n";
	::SETMOTORDOWN = false;
	::SETMOTORUP = false;
	::SETBEAM = false;
}
void Closed::Exit(){

}


void Closing::Entry(){
	std::cout << "Garage Door Closing, beam on" << std::endl;
	::SETMOTORDOWN = true;
	::SETMOTORUP = false;
	::SETBEAM = true;
}
void Closing::Exit(){
	std::cout << "Beam off" << std::endl;
}



void Open::Entry(){
	std::cout << "Garage door opened" << std::endl;
	::SETMOTORDOWN = false;
	::SETMOTORUP = false;
	::SETBEAM = false;
}

void Open::Exit(){

}


void Opening::Entry(){
	std::cout << "Garage Door Opening, beam on\n" << std::endl;
	::SETMOTORDOWN = false;
	::SETMOTORUP = true;
	::SETBEAM = false;
}

void Opening::Exit(){
	std::cout << "Beam off\n" << std::endl;
}

void StoppedClosing::Entry(){
	std::cout << "Garage Door Stopped Closing\n" << std::endl;
	::SETMOTORDOWN = false;
	::SETMOTORUP = false;
	::SETBEAM = false;
	}

void StoppedClosing::Exit(){

}

void StoppedOpening::Entry(){
	std::cout << "Garage Door Stopped Opening, beam off\n" << std::endl;
	::SETMOTORDOWN = false;
	::SETMOTORUP = false;
	::SETBEAM = false;
	}
void StoppedOpening::Exit(){

}

