#include "ClosedState.h"
#include "StateContext.h"
#include "LockedState.h"
#include "OpennedState.h"
#include<iostream>


void ClosedState::opendoor() {
	cout << "--Door is opened" << endl;
	this->m_statect->transition(new OpennedState);
}

void ClosedState::lockdoor() {
	cout << "--Door is locked" << endl;
	this->m_statect->transition(new LockedState);

}

void ClosedState::unlockdoor(){
	cout << "--Door is unlocked " << endl;

}

void ClosedState::closedoor(){
	cout << "--Door is closed " << endl;
	
}