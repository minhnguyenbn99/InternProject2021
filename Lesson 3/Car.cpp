#include "Car.h"
Car::Car() :DynamicObject()
{
	this->model = "";

}
Car::Car(string id, string name, int speed, string model) : DynamicObject(id, name, speed) {
	this->model = model;
}


void Car::move()
{
	Position pos = this->getPosition();
	pos.x += 10;
	pos.y += 10;
	setPosition(pos);
	DynamicObject::move();
	cout << "  x increase to " << pos.x << " and y increase to " << pos.y << endl;
}