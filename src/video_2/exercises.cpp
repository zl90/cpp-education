#include <iostream>
#include <string>

using namespace std;

// Exercise 2: Create a function that calculates the factorial of a given number using a recursive approach.
int factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

void runTests()
{
    factorial(0) == 1 ? cout << "factorial(0):\tpassed!" << endl : cout << "factorial(0):\tfailed..." << endl;
    factorial(4) == 24 ? cout << "factorial(4):\tpassed!" << endl : cout << "factorial(4):\tfailed..." << endl;
    factorial(-1) == 1 ? cout << "factorial(-1):\tpassed!" << endl : cout << "factorial(-1):\tfailed..." << endl;

    return;
}

int main()
{
    runTests();
}