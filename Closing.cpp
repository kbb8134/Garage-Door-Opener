#include "Closing.h"

void Closing::Entry(){
	std::cout << "Garage Door Closing, beam on" << std::endl;
	reciever->setmotorDown(true);
	reciever->setmotorUp(false);
	reciever->setBeam(true);
}

void Closing::Exit(){
	std::cout << "Beam off" << std::endl;
}



