#pragma once
#include "DynamicObject.h"
class Motorbike :public DynamicObject
{
private:
	int capacity;
public:
	Motorbike();
	Motorbike(string id, string name, int speed, int capacity);
	void move();

};