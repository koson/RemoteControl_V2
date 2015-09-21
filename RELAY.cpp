// 
// 
// 

#include "RELAY.h"


void RELAYClass::init(int value)
{
	this->pin = value;
	this->pinStatus = false;
	digitalWrite(pin, LOW);
	pinMode(pin, OUTPUT);
}

void RELAYClass::ON()
{
	pinStatus = true;
	digitalWrite(pin, HIGH);
}
void RELAYClass::OFF()
{
	pinStatus = false;
	digitalWrite(pin, LOW);
}

void RELAYClass::Toggle()
{
	if (pinStatus == true)
	{
		digitalWrite(pin, LOW);
		pinStatus = false;
	}
	else
	{
		digitalWrite(pin, HIGH);
		pinStatus = true;
	}

}

 RELAYClass RELAY;

