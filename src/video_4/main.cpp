#include <iostream>
#include <string>

using namespace std;

// Abstract class:
class LivingThing
{
public:
    virtual void makeNoise() = 0; // This class is now abstract.
    // Abstract classes cannot be instantiated.
    // All virtual methods must be overriden by child classes.
};

class Animal : public LivingThing
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

// Inheritance:
class Dog : public Animal
{
protected:
    string breed;

public:
    Dog()
    {
        Animal();
        name = "Dog";
        breed = "Corgi";
    }

    Dog(string cBreed, int cAge, string cName)
    {
        name = cName;
        breed = cBreed;
        age = cAge;
    }

    void makeNoise()
    {
        cout << name << " barks loudly!\n";
    }
};

// You can pass objects as pointers
void passObjectByPointer(Animal *object)
{
    object->makeNoise();
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
    passObjectByPointer(falcon);
    delete (falcon); // Free the memory after use

    // You can pass anonymous objects to functions:
    passObjectByPointer(new Animal(4, "Aardvark"));

    Dog *borderCollie = new Dog("Border Collie", 3, "Mr Bingles");
    borderCollie->makeNoise();
    borderCollie->sleep();

    return 0;
}