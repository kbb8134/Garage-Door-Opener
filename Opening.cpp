#include "Opening.h"

void State::Entry(){
	std::cout << "Garage Door Opening, beam on\n" << std::endl;
	reciever.setmotorDown(false);
	reciever.setmotorUp(true);
	reciever.setBeam(false);
}

void State::Exit(){
	std::cout << "Beam off\n" << std::endl;
}
