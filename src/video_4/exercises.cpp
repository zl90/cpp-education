#include "person.h"
using namespace std;

int main()
{
    // Exercise 1: Classes
    Person *myPerson = new Person();
    myPerson->Crawl();
    myPerson->Stand();
    myPerson->Walk();
    myPerson->Run();

    // Exercise 2: Inheritance
    Soldier *mySoldier = new Soldier();
    mySoldier->Stand(); // Inherited method
    mySoldier->FireWeapon();

    return 0;
}