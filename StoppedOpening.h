#ifndef StoppedOpening_h
#define StoppedOpening_h

#include "State.h"


class StoppedOpening : public State {

public:
	void Entry();
	void Exit(){};
};

#endif // StoppedOpening_h
