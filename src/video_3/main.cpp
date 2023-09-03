#include <iostream>
#include <string>

using namespace std;

void adjustByValue(int);
void adjustByReference(int &);
void adjustByPointer(int *);

int main()
{
    int myInt = 5;
    adjustByValue(myInt);
    cout << "myInt after adjustByValue:\t" << myInt << endl;
    adjustByReference(myInt);
    cout << "myInt after adjustByReference:\t" << myInt << endl;
    adjustByPointer(&myInt);
    cout << "myInt after adjustByPointer:\t" << myInt << endl;
}

void adjustByValue(int value)
{
    value = 10;
}

void adjustByReference(int &reference)
{
    reference = 10;
}

void adjustByPointer(int *pointer)
{
    *pointer = 20;
}
