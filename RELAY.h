// RELAY.h

#ifndef _RELAY_h
#define _RELAY_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class RELAYClass
{
 protected:
	 int pin;
	 bool pinStatus;

 public:
 
	 void init(int pin);
	 void ON();
	 void OFF();
	 void Toggle();

	 //RELAYClass(int pin);


};

extern RELAYClass RELAY;

#endif

