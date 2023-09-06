#include <iostream>
#include <string>

using namespace std;

// Exercise 1:
class GameObject
{
public:
    int id;

    GameObject()
    {
        this->id = 100;
    }

    // Exercise 2: non-default constructor
    GameObject(int pId)
    {
        this->id = pId;
    }
};

void runTests()
{
    GameObject obj1;
    GameObject obj2(45);

    obj1.id == 100 ? cout << "Test1:\tpassed!\n" : cout << "Test1:\tfailed...\n";
    obj2.id == 45 ? cout << "Test2:\tpassed!\n" : cout << "Test2:\tfailed...\n";
}

int main()
{
    runTests();

    return 0;
}