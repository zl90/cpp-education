#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Basic testing helper:
template <typename T, typename K>
void expect(string name, T lhs, K rhs)
{
    lhs == rhs ? cout << "\033[32m" << name << ":\tpassed!\n" : cout << "\033[31m" << name << ":\tfailed...\n";
    cout << "\033[0m";
}

// Exercise 1: class hierarchy
class Vehicle
{
protected:
    int id;

private:
    int damage;

public:
    Vehicle(int id, int damage)
    {
        this->id = id;
        this->damage = damage;
    }
    string Display()
    {
        stringstream output;
        output << "id = " << id << ", damage = " << damage << "\n";
        return output.str();
    }
};

class Boat : public Vehicle
{
public:
    Boat(int id, int damage) : Vehicle(id, damage) {}
    // Exercise 2: calling the parent member function:
    string Display()
    {
        return Vehicle::Display();
    }
};

class Car : public Vehicle
{
public:
    Car(int id, int damage) : Vehicle(id, damage) {}
    string Display()
    {
        return Vehicle::Display();
    }
};

void runTests()
{
    Vehicle *v1 = new Vehicle(1, 30);
    Boat *b1 = new Boat(2, 50);
    Car *c1 = new Car(3, 40);

    // Exercise 3: static array of pointers
    Vehicle *vehicles[5];
    vehicles[0] = new Car(1, 35);
    vehicles[1] = new Boat(2, 55);
    vehicles[2] = new Vehicle(3, 30);
    vehicles[3] = new Car(4, 25);
    vehicles[4] = new Boat(5, 65);

    expect("Test1", v1->Display(), "id = 1, damage = 30\n");
    expect("Test2", b1->Display(), "id = 2, damage = 50\n");
    expect("Test3", c1->Display(), "id = 3, damage = 40\n");
    expect("Test4", vehicles[3]->Display(), "id = 4, damage = 25\n");
    expect("Test5", vehicles[1]->Display(), "id = 2, damage = 55\n");
    expect("Test6", vehicles[0]->Display(), "id = 1, damage = 35\n");
}

int main()
{
    runTests();

    return 0;
}