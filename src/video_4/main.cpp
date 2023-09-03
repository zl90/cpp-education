#include <iostream>
#include <string>

using namespace std;

class Animal
{
protected:
    int age;
    string name;

public:
    // Default constructor
    Animal()
    {
        age = 1;
        name = "Animal";
    };

    // Non-default constructor
    Animal(int cAge, string cName)
    {
        age = cAge;
        name = cName;
    };

    // Alternate constructor syntax:
    // Animal(int cAge, string cName) : age(cAge), name(cName){};

    void makeNoise();
    void sleep();
};

void Animal::makeNoise()
{
    cout << name << " makes a noise!\n";
}

void Animal::sleep()
{
    cout << name << " falls asleep. Zzzzz.\n";
}

int main()
{
    // Creating and using static objects:
    Animal eagle(5, "Eagle");
    eagle.makeNoise();
    eagle.sleep();

    Animal cow(29, "Cow");
    cow.makeNoise();
    cow.sleep();

    // Creating and using dynamic objects:
    Animal *falcon = new Animal(6, "Falcon");
    falcon->makeNoise(); // Dereference method
    falcon->sleep();
    delete (falcon); // Free the memory after use

    return 0;
}