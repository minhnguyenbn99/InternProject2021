#include "Motorbike.h"
Motorbike::Motorbike() :DynamicObject()
{
	this->capacity = 0;
}
Motorbike::Motorbike(string id, string name, int speed, int capacity) : DynamicObject(id, name, speed) {
	this->capacity = capacity;
}

void Motorbike::move()
{
	Position pos = this->getPosition();
	pos.x += 5;
	pos.y += 5;
	setPosition(pos);
	DynamicObject::move();
	cout << "  x increase to " << pos.x <<" and y increase to " << pos.y <<endl;


}