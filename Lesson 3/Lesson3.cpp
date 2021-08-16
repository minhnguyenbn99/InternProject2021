#include <iostream>
#include"ListObject.h"
using namespace std;

int main() {

    vector<BaseObject*> listObj;

    BaseObject* motorbike = new Motorbike("Mtb01", "wave2021", 80, 2);
    BaseObject* car = new Car("C01", "Hyundai", 120, "i10");
    BaseObject* tree = new Tree("Tr01", "Mangosteen", true, "Mangostana");
    BaseObject* house = new House("H01", "VHOP", false, 80);

    listObj.push_back(motorbike);
    listObj.push_back(car);
    listObj.push_back(tree);
    listObj.push_back(house);
    
    cout << "NAME OF OBJECT" << endl;

    for (auto obj : listObj) {
        cout << obj->getName() << endl;
    }
    cout << endl;

    cout << "POSITION BEFORE MOVE" << endl;
    cout << endl;

    for (auto obj : listObj) {
        obj->printPosition();
    }

    cout << "UPDATE MOVE" << endl;
    cout << endl;

    for (auto obj : listObj) {
        obj->move();
    }

    cout << endl;
    cout << "POSITION AFTER MOVE" << endl;
    cout << endl;

    for (auto obj : listObj) {
        obj->printPosition();
    }

    listObj.clear();

}