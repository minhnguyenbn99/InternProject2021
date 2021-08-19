#pragma once
#include "StateContext.h"
#include<iostream>
using namespace std;
class StateBase
{
protected:
	StateContext* m_statect;
public:
	void setcontext(StateContext* statect) {
		this->m_statect = statect;
	}
	virtual void unlockdoor()=0;
	virtual void lockdoor()=0;
	virtual void opendoor()=0;
	virtual void closedoor()=0;

};