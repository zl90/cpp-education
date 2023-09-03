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

// Exercise 6: Create a program that calculates the absolute value of a number using the ternary operator.
signed int abs(signed int n)
{
    int result;
    (n < 0) ? result = n *-1 : result = n;
    return result;
}

void runTests()
{
    factorial(0) == 1 ? cout << "factorial(0):\tpassed!" << endl : cout << "factorial(0):\tfailed..." << endl;
    factorial(4) == 24 ? cout << "factorial(4):\tpassed!" << endl : cout << "factorial(4):\tfailed..." << endl;
    factorial(-1) == 1 ? cout << "factorial(-1):\tpassed!" << endl : cout << "factorial(-1):\tfailed..." << endl;

    abs(-10) == 10 ? cout << "abs(-10):\tpassed!" << endl : cout << "abs(-10):\tfailed... " << abs(-10) << endl;
    abs(5) == 5 ? cout << "abs(5):\t\tpassed!" << endl : cout << "abs(5):\tfailed..." << endl;

    return;
}

int main()
{
    runTests();
}