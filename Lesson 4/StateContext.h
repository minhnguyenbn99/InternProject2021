#pragma once
//#include "ClosedState.h"
class StateBase;
class StateContext
{
private:
	StateBase* m_state;
public:
	StateContext(StateBase* state);
	~StateContext();

	void transition(StateBase* state);

	void transitionToOpen();
	void transitionToLock();
	void transitionToUnLock();
	void transitionToClose();
	
};
