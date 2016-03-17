#include "Opening.h"

void Opening::Entry(){
	std::cout << "Garage Door Opening, beam on\n" << std::endl;
	reciever->setmotorDown(false);
	reciever->setmotorUp(true);
	reciever->setBeam(false);
}

void Opening::Exit(){
	std::cout << "Beam off\n" << std::endl;
}
