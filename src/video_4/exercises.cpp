#include "person.h"
using namespace std;

int main()
{
    // Exercise 1:
    Person *myPerson = new Person();
    myPerson->Crawl();
    myPerson->Stand();
    myPerson->Walk();
    myPerson->Run();

    return 0;
}