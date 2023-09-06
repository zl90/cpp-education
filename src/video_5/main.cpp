#include <iostream>
#include <string>

using namespace std;

class MyClass
{
private:
    int value;

public:
    // Default constructor
    MyClass()
    {
        value = 0;
    }

    // Non-default constructor
    MyClass(int v)
    {
        value = v;
    }

    // Member initialiser (shorthand constructor)
    // MyClass(int theValue) : value(theValue) {}
};

class Model
{
private:
    int id;

public:
    Model() // The parent constructor is invoked automatically from child constructors
    {
        cout << "Model constructor invoked in \n";
    }

    Model(int modelID)
    {
        id = modelID;
    }

    // `this` is a pointer to the current object:
    void printID()
    {
        cout << this->id << endl;
    }
};

class Car : public Model
{
public:
    Car()
    {
        cout << "Car constructor invoked \n";
    }

    Car(int carID) : Model(carID) {}
};

class Command
{
public:
    int id;
    Command(int id) : id(id) {}
    void Print() { cout << this->id << endl; }
};

class NPC
{
public:
    int *age;

    NPC()
    {
        age = new int(20);
    }

    NPC(const NPC &obj)
    {
        this->age = obj.age; // Shallow copy pointer.

        cout << "Shallow copy constructor invoked" << endl;
    }

    NPC(const NPC &obj, int dummy)
    {
        age = new int(*obj.age); // Allocate new memory for a deep copy.

        cout << "Deep copy constructor invoked" << endl;
    }

    void Perform(Command &c)
    {
        c.Print();
    }
};

int main()
{
    Car *car = new Car(3);

    Command cmd(20);
    NPC npc;
    cmd.Print();
    npc.Perform(cmd); // Passing objects by reference

    NPC npc2(npc);    // Invokes the copy constructor
    NPC npc3 = npc;   // Invokes the copy constructor
    NPC npc4(npc, 0); // Invoke deep copy constructor
    *npc3.age = 25;
    cout << *npc2.age << endl;
    cout << *npc3.age << endl;
    cout << *npc4.age << endl;
    cout << npc2.age << endl; // These two point to the same memory address
    cout << npc3.age << endl; // These two point to the same memory address
    cout << npc4.age << endl; // This one points to a different memory address.

    return 0;
}