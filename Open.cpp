#include "Open.h"


void State::Entry()
{
	std::cout << "Garage door opened" << std::endl;
	reciever.setmotorDown(false);
	reciever.setmotorUp(false);
	reciever.setBeam(false);
}
