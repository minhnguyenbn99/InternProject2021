#pragma once
#include "BaseObject.h"
class DynamicObject :public  BaseObject
{
protected:
	int speed;
public:
	DynamicObject();
	DynamicObject(string id, string name, int speed);
	void move();

};