#pragma once
#include "DynamicObject.h"

class Car : public DynamicObject

{
private:string model;
public:
	Car();
	Car(string id, string name, int speed, string model);
	void move();
};