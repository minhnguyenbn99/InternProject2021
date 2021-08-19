#include "OpennedState.h"
#include "StateContext.h"
#include "ClosedState.h"
#include "LockedState.h"
#include<iostream>



void OpennedState::opendoor()
{
	cout << "--Door is open" << endl;

}

void OpennedState::closedoor()
{
	cout << "--Door is closed" << endl;
	this->m_statect->transition(new ClosedState);

}


void OpennedState::unlockdoor()
{
	cout << "--Door is open" << endl;

}

void OpennedState::lockdoor()
{
	cout << "--Door is open" << endl;
	
}