#pragma once
#include "BaseObject.h"
class StaticObject : public BaseObject

{
protected:
	bool isLive;
public:
	StaticObject();
	StaticObject(string id, string name, bool isLive);
	void move();

};