#include <iostream>
using namespace std;

// A Pointer is a variable that holds the memory address of a variable.
int main()
{
    int a = 42;
    int *b = 0; // Pointers should always be initialised as they are undetermined at declaration.

    b = &a; // Use the reference operator to assign the pointer to a memory address.

    cout << b << endl;  // Displays the memory address of `a`.
    cout << *b << endl; // Dereferences the pointer to display the value of the original variable.

    return 0;
}