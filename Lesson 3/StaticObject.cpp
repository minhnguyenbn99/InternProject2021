#include "StaticObject.h"
StaticObject::StaticObject() :BaseObject()
{
	this->isLive = false;
}
StaticObject::StaticObject(string id, string name, bool isLive) : BaseObject(id, name) {
	this->isLive = isLive;
}


void StaticObject::move()
{
	cout << "CAN NOT MOVE" << endl;
}
