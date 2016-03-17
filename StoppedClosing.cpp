#include "StoppedClosing.h"

void State::Entry(){
	std::cout << "Garage Door Closing\n" << std::endl;
	reciever->setmotorDown(false);
	reciever->setmotorUp(false);
	reciever->setBeam(false);
}
