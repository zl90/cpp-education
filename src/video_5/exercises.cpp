#include <iostream>
#include <string>

using namespace std;

// Exercise 5:
class Location
{
public:
    int x;
    int y;
    int z;

    Location()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    Location(int px, int py, int pz)
    {
        x = px;
        y = py;
        z = pz;
    }

    void Set(int px, int py, int pz)
    {
        x = px;
        y = py;
        z = pz;
    }

    void Display()
    {
        cout << "x: " << x << ", y: " << y << ", z: " << z << endl;
    }
};

// Exercise 1:
class GameObject
{
public:
    int id;
    Location *location;

    // Exercise 3: static data members
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

    GameObject(int id, Location *location)
    {
        this->id = id;
        this->location = location;
        this->instanceCount++;
    }
};

int GameObject::instanceCount = 0;

void runTests()
{
    GameObject obj1(100, new Location(1, 1, 1));
    GameObject obj2(45, new Location(2, 2, 2));

    obj1.id == 100 ? cout << "Test1:\tpassed!\n" : cout << "Test1:\tfailed...\n";
    obj2.id == 45 ? cout << "Test2:\tpassed!\n" : cout << "Test2:\tfailed...\n";
    GameObject::instanceCount == 2 ? cout << "Test3:\tpassed!\n" : cout << "Test3:\tfailed...\n";
    obj1.location->x == 1 ? cout << "Test4:\tpassed!\n" : cout << "Test4:\tfailed...\n";
    obj2.location->x == 2 ? cout << "Test4:\tpassed!\n" : cout << "Test4:\tfailed...\n";
}

int main()
{
    runTests();

    return 0;
}