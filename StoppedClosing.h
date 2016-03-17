#ifndef StoppedClosing_h
#define StoppedClosing_h

#include "State.h"


class StoppedClosing : public State {
public:
	void Entry();
	void Exit(){};

};

#endif // StoppedClosing_h
