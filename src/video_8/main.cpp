#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
    Animal() {}
    string roar()
    {
        return "Roar!";
    }
};

void foo()
{
    cout << "bar" << endl;
}

int add(int a, int b)
{
    return a + b;
}

// Function templates:
template <typename T>
T getMax(T a, T b)
{
    T result;
    result = a > b ? a : b;
    return result;
}

// Class templates:
template <class K>
class Vector2D
{
private:
    K coordinate[2];

public:
    Vector2D(K x, K y)
    {
        coordinate[0] = x;
        coordinate[1] = y;
    }
    void Display()
    {
        cout << "x: " << coordinate[0] << ", y: " << coordinate[1] << endl;
    }
};

int main()
{
    // Pointer to a function with no arguments:
    void (*bar)() = foo;
    bar();

    // Pointer to a function with arguments:
    int (*addPointer)(int, int) = add;
    cout << addPointer(1, 1) << endl;

    // You can set up an alias for doing this more concisely:
    typedef int (*AddPtr)(int, int);
    AddPtr addPointer2 = add;
    AddPtr addPointer3 = add;
    AddPtr addPointer4 = add;
    cout << addPointer2(1, 1) << endl;
    cout << addPointer3(1, 1) << endl;
    cout << addPointer4(1, 1) << endl;

    // Pointer to a *member* function:
    string (Animal::*roarPointer)() = &Animal::roar;
    Animal myAnimal;
    string answer = (myAnimal.*roarPointer)();
    cout << answer << endl;

    // Using function templates:
    cout << getMax<int>(2, 3) << endl;
    cout << getMax<float>(11.3, 3.1) << endl;
    cout << getMax<char>('A', 'Z') << endl;

    // Using class templates:
    Vector2D<int> v(2, 3);
    Vector2D<float> v2(2.222, 3.003);
    v.Display();
    v2.Display();

    return 0;
}