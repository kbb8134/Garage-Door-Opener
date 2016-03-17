#include "StoppedOpening.h"

void StoppedOpening::Entry(){
	std::cout << "Garage Door Stopped Opening, beam off\n" << std::endl;
	reciever->setmotorDown(false);
	reciever->setmotorUp(false);
	reciever->setBeam(false);
}

