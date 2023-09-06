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

    GameObject(const GameObject &obj)
    {
        this->id = obj.id;
        // Exercise 6: deep copy:
        this->location = new Location(obj.location->x, obj.location->y, obj.location->z);
        this->instanceCount++;
    }
};

int GameObject::instanceCount = 0;

void runTests()
{
    GameObject obj1(100, new Location(1, 1, 1));
    GameObject obj2(45, new Location(2, 2, 2));
    GameObject obj6 = obj2;

    obj1.id == 100 ? cout << "\033[32mTest1:\tpassed!\n" : cout << "\033[31mTest1:\tfailed...\n";
    obj2.id == 45 ? cout << "\033[32mTest2:\tpassed!\n" : cout << "\033[31mTest2:\tfailed...\n";
    GameObject::instanceCount == 3 ? cout << "\033[32mTest3:\tpassed!\n" : cout << "\033[31mTest3:\tfailed...\n";
    obj1.location->x == 1 ? cout << "\033[32mTest4:\tpassed!\n" : cout << "\033[31mTest4:\tfailed...\n";
    obj2.location->x == 2 ? cout << "\033[32mTest5:\tpassed!\n" : cout << "\033[31mTest5:\tfailed...\n";

    obj6.location->Set(8, 8, 8);

    obj2.location->x == 2 ? cout << "\033[32mTest6:\tpassed!\n" : cout << "\033[31mTest6:\tfailed...\n";
    obj6.location->x == 8 ? cout << "\033[32mTest7:\tpassed!\n" : cout << "\033[31mTest7:\tfailed...\n";
    cout << "\033[0m";
}

int main()
{
    runTests();

    return 0;
}