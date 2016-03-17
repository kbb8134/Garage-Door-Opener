#include "Open.h"


void Open::Entry()
{
	std::cout << "Garage door opened" << std::endl;
	reciever->setmotorDown(false);
	reciever->setmotorUp(false);
	reciever->setBeam(false);
}
