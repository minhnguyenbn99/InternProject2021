#pragma once
#include"BaseObject.h"
#include"Car.h"
#include"DynamicObject.h"
#include"House.h"
#include"Motorbike.h"
#include"Tree.h"
#include"StaticObject.h"
#include<vector>

class ListObject
{
public:
	vector<BaseObject*> ls;
	~ListObject();
};
