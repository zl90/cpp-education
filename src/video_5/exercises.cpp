#include <iostream>
#include <string>

using namespace std;

// Exercise 1:
class GameObject
{
public:
    int id;

    // Exercise 3: static member data
    static int instanceCount;

    GameObject()
    {
        this->id = 100;
        this->instanceCount++;
    }

    // Exercise 2: non-default constructor
    GameObject(int pId)
    {
        this->id = pId;
        this->instanceCount++;
    }
};

int GameObject::instanceCount = 0;

void runTests()
{
    GameObject obj1;
    GameObject obj2(45);

    obj1.id == 100 ? cout << "Test1:\tpassed!\n" : cout << "Test1:\tfailed...\n";
    obj2.id == 45 ? cout << "Test2:\tpassed!\n" : cout << "Test2:\tfailed...\n";
    GameObject::instanceCount == 2 ? cout << "Test3:\tpassed!\n" : cout << "Test3:\tfailed...\n";
}

int main()
{
    runTests();

    return 0;
}