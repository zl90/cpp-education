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
};

void runTests()
{
    GameObject obj1;

    obj1.id == 100 ? cout << "Test1:\tpassed!\n" : cout << "Test1:\tfailed...\n";
}

int main()
{
    runTests();

    return 0;
}