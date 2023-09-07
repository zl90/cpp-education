#include <iostream>
#include <string>

using namespace std;

class GameObject
{
public:
    int id;

    GameObject() {}
    GameObject(int id) : id(id) {}

    void Display()
    {
        cout << "ID = " << id << endl;
    }
};

class Group
{
private:
    GameObject *objects;
    int size;

public:
    Group(int n) : size(n)
    {
        objects = new GameObject[size];
        for (int i = 0; i < n; i++)
        {
            objects[i].id = i;
        }
    }

    void Display()
    {
        for (int i = 0; i < size; i++)
        {
            objects[i].Display();
        }
    }
};

class Model
{
public:
    virtual void Draw()
    {
        cout << "Draw Model \n";
    }
};

class Car : public Model
{
public:
    void Draw()
    {
        cout << "Draw Car \n";
    }
};

int main()
{
    // Statically sized Arrays of objects:
    GameObject objArray[3];

    for (int i = 0; i < 3; i++)
    {
        objArray[i].id = i;
    }

    for (int i = 0; i < 3; i++)
    {
        objArray[i].Display();
    }

    // Dynamically sized arrays of objects:
    GameObject *objArray2;
    objArray2 = new GameObject[3];

    for (int i = 0; i < 3; i++)
    {
        objArray2[i].id = i;
    }

    for (int i = 0; i < 3; i++)
    {
        objArray2[i].Display();
    }

    Group g1(4);
    g1.Display();

    // Static arrays of pointers to objects:
    GameObject *objArray3[3];

    for (int i = 0; i < 3; i++)
    {
        objArray3[i] = new GameObject(i);
    }

    for (int i = 0; i < 3; i++)
    {
        objArray3[i]->Display();
    }

    // Dynamic arrays of pointers to objects:
    GameObject **objArray4; // Pointer to an array of pointers
    objArray4 = new GameObject *[3];

    for (int i = 0; i < 3; i++)
    {
        objArray4[i] = new GameObject(i);
    }

    for (int i = 0; i < 3; i++)
    {
        objArray4[i]->Display();
    }

    // Dynamic 2 dimensional arrays:
    int **array2D;
    array2D = new int *[5];

    for (int i = 0; i < 5; i++)
    {
        array2D[i] = new int[5];
    }

    array2D[0][0] = 53;

    // Polymorphism:
    Model *model = new Model();
    Car *car = new Car();
    model->Draw();
    car->Draw();

    return 0;
}