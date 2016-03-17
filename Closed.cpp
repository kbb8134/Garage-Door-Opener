#include <cstdio>
#include <iostream>

#include "Closed.h"

void State::Entry(){
	std::cout << "Garage Door Closed. Beam off\n";
	reciever->setmotorDown(false);
	reciever->setmotorUp(false);
	reciever->setBeam(false);
}
