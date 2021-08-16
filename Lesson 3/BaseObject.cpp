#include "BaseObject.h"
BaseObject::BaseObject()
{
	this->id = "";
	this->name = "";
	this->position.x = 0;
	this->position.y = 0;

}
BaseObject::~BaseObject()
{
}

BaseObject::BaseObject(string id, string name)
{
	this->id = id;
	this->name = name;
	this->position.x = 0;
	this->position.y = 0;

}

void BaseObject::setPosition(Position pos) {
	this->position.x = pos.x;
	this->position.y = pos.y;
}

Position BaseObject::getPosition()
{
	return this->position;
}

string BaseObject::getName()
{
	return this->name;
}



void BaseObject::printPosition()
{
	cout << "POSITION : ( " << this->position.x << ", " << this->position.y << " )" << endl;

}

