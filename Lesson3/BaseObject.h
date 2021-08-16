#pragma once
#include<iostream>
#include<string>
#include<math.h>
using namespace std;
struct Position {
	int x;
	int y;
};

class BaseObject {
private:
	string id;
	string name;
	Position position;
public:
	BaseObject();
	~BaseObject();
	BaseObject(string id, string name);
	string getName();
	void setPosition(Position pos);
	Position getPosition();
	virtual void move() = 0;
	void printPosition();

};
