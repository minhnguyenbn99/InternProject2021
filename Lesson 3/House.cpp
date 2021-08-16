#include "House.h"
House::House() :StaticObject()
{
    this->area = 0;
}
House::House(string id, string name, bool isLive, int area) : StaticObject(id, name, isLive) {
    this->area = area;
}
void House::move()
{
    StaticObject::move();
}
