#ifndef Globals_h
#define Globals_h

//Mutex is false when no thread is currently reading or setting any of the global variables
	 extern bool MUTEX;
	 extern bool INTERRUPT;
	 extern bool BUTTON;
	 extern bool OVERCURRENT;
//TRANSITIONED lets garagedooropener know if a state transition happened
	extern bool TRANSITIONED;
	extern bool SETMOTORDOWN;
	extern bool SETMOTORUP;
	extern bool SETBEAM;
//	enum STATE {CLOSED, CLOSING, OPENED, OPENING, AJAR};

#endif

