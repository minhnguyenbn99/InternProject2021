#include "StateContext.h"
#include "OpennedState.h"
#include "ClosedState.h"


StateContext::StateContext(StateBase* state) :m_state(nullptr) {
	this->transition(state);

}
StateContext::~StateContext() {
	delete m_state;
}
void StateContext::transition(StateBase* state) {
	if (this->m_state != nullptr) delete this->m_state;
	this->m_state = state;
	this->m_state->setcontext(this);
}

void StateContext::transitionToOpen() {
	this->m_state->opendoor();
}

void StateContext::transitionToLock() {
	this->m_state->lockdoor();
}

void StateContext::transitionToUnLock() {
	this->m_state->unlockdoor();
}

void StateContext::transitionToClose() {
	this->m_state->closedoor();
}