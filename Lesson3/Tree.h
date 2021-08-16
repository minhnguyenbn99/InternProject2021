#pragma once
#include"StaticObject.h"
class Tree :public StaticObject
{
	string species;
public:
	Tree();
	Tree(string id, string name, bool isLive, string species);
	void move();

};


