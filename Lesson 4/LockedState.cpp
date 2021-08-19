#include "LockedState.h"
#include "StateContext.h"
#include "ClosedState.h"
#include<iostream>

void LockedState::opendoor()
{
	cout << "--Door is locked" << endl;
}

void LockedState::lockdoor()
{
	cout << "--Door is locked" << endl;

}

void LockedState::unlockdoor()
{
	cout << "--Door is unlocked" << endl;
	this->m_statect->transition(new ClosedState);

}

void LockedState::closedoor()
{
	cout << "--Door is locked" << endl;
}