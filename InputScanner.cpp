#include "GarageDoorOpener.h"


// Input scanner thread
// to be run at 1Hz
void* InputScanner::InputScannerThread(void* arg)
{
	char userChoice = 'x';
	// Start the scanning
	do{
		std::cout << "\nEnter your choice: [ ";
		std::cout << "'m' : to indicate motor overcurrent | "
				  << "'i' : to indicate infrared beam interruption | "
				  << "'r' : to indicate remote button press ] : ";

		std::cin >> userChoice;

		switch(tolower(userChoice))
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

			case 'e': // remote button press
				std::cout << "\nExiting the InputScannerThread..." << std::endl << std::endl;
				return 0;

			default:
				std::cout << "\nInvalid option. Try again" << std::endl << std::endl;
		}

	} while(true);

	return 0;
}


void InputScanner::alertOvercurrent()
{
	if(MUTEX == false){
		MUTEX = true;
		if(OVERCURRENT != true && INTERRUPT != true && BUTTON != true){
			OVERCURRENT = true;
		}
		MUTEX = false;
	}
}

void InputScanner::alertbeam()
{
	if(MUTEX == false){
		MUTEX = true;
		if(OVERCURRENT != true && INTERRUPT != true && BUTTON != true){
			INTERRUPT = true;
		}
		MUTEX = false;
	}
}


void InputScanner::alertbutton()
{
	if(MUTEX == false){
		MUTEX = true;
		if(OVERCURRENT != true && INTERRUPT != true && BUTTON != true){
			BUTTON = true;
		}
		MUTEX = false;
	}
}


