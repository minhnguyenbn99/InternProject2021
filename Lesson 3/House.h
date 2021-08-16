#pragma once
#include"StaticObject.h"
class House :public StaticObject
{
protected:
	int area;
public:
	House();
	House(string id, string name, bool isLive, int area);
	void move();
};

