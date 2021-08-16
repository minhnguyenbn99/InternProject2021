#include "Tree.h"
Tree::Tree() :StaticObject()
{
	this->species = "";

}
Tree::Tree(string id, string name, bool isLive, string species) : StaticObject(id, name, isLive) {
	this->species = species;
}

void Tree::move()
{
	StaticObject::move();
}