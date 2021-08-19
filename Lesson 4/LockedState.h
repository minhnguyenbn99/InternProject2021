#pragma once
#include "StateBase.h"
class LockedState :public StateBase
{
public:

	void opendoor();
	void lockdoor();
	void unlockdoor();
	void closedoor();
	
};