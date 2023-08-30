#include <iostream>
using namespace std;

int main()
{
    int age(25);          // variables are aliases for memory addresses
    cout << &age << endl; // displays the memory address itself (the `lvalue`)

    return 0;
}