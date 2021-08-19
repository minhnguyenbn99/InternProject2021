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
	

}

void ClosedState::unlockdoor(){
	cout << "--Door is closed " << endl;

}

void ClosedState::closedoor(){
	cout << "--Door is closed " << endl;
	this->m_statect->transition(new LockedState);
}