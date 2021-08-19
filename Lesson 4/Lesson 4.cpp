#include<iostream>
#include"StateContext.h"
#include"OpennedState.h"
#include"ClosedState.h"
using namespace std;
void test() {
	StateContext* teststate = new StateContext(new ClosedState);
	cout << " State init: Close" << endl;
	teststate->transitionToOpen();
	teststate->transitionToClose();
	teststate->transitionToLock();
	teststate->transitionToUnLock();
	
	delete teststate;
}
int main()
{
	test();
	_CrtDumpMemoryLeaks;
	system("Pause");
	return 0;

}