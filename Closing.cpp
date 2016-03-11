#include "Closing.h"

void State::Entry(){
	std::cout << "Garage Door Closing, beam on" << std::endl;
	reciever.setmotorDown(true);
	reciever.setmotorUp(false);
	reciever.setBeam(true);
}

void State::Exit(){
	std::cout << "Beam off" << std::endl;
}



