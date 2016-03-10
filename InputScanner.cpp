#include "InputScanner.h"
#include "Globals.h"
#include <iostream>

// Input scanner thread
// to be run at 1Hz
void* InputThread(void* arg)
{
	char userChoice = 'x';
	// Start the scanning
	do{
		std::cout << "\nEnter your choice: [ ";
		std::cout << "'m' : to indicate motor overcurrent | "
				  << "'i' : to indicate infrared beam interruption | "
				  << "'r' : to indicate remote button press ] : ";

		std::cin >> userChoice;

		//switch(tolower(userChoice))
		switch(userChoice)
		{
			case 'm': // motor overcurrent
				((InputScanner*)arg)->alertOvercurrent(); // set the shared variable
				break;

			case 'i': // infrared beam interruption
				((InputScanner*)arg)->alertbeam(); // set the shared variable
				break;

			case 'r': // remote button press
				nanospin_ns(1E9); // simulate a 1 second press
				((InputScanner*)arg)->alertbutton(); // set the shared variable
				break;

			default:
				std::cout << "\nInvalid option. Try again" << std::endl << std::endl;
		}

	} while((userChoice) != 'x');
	//while(tolower(userChoice) != 'x');

	return 0;
}


void InputScanner::alertOvercurrent()
{
	if(MUTEX == false){
		MUTEX = true;
		OVERCURRENT = true;
		MUTEX = false;
	}
}

void InputScanner::alertbeam()
{
	if(MUTEX == false){
		MUTEX = true;
		INTERRUPT = true;
		MUTEX = false;
	}
}


void InputScanner::alertbutton()
{
	if(MUTEX == false){
		MUTEX = true;
		BUTTON = true;
		MUTEX = false;
	}
}


