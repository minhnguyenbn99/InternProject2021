#include "DynamicObject.h"
DynamicObject::DynamicObject() : BaseObject()
{
	this->speed = 0;
}

DynamicObject::DynamicObject(string id, string name, int speed) : BaseObject(id, name)
{
	this->speed = speed;
}

void DynamicObject::move() {
	cout << "CAN MOVE" << endl;
}