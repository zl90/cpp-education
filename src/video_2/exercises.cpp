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
    (n < 0) ? result = n * (-1) : result = n;
    return result;
}

// Exercise 10: Write a program that checks if a given year is a leap year (divisible by 4 and not divisible by 100, unless divisible by 400) using logical operators.
bool isLeapYear(int year)
{
    return (year % 4 == 0) && ((year % 400 == 0) || (year % 100 != 0));
}

void runTests()
{
    factorial(0) == 1 ? cout << "factorial(0):\tpassed!" << endl : cout << "factorial(0):\tfailed..." << endl;
    factorial(4) == 24 ? cout << "factorial(4):\tpassed!" << endl : cout << "factorial(4):\tfailed..." << endl;
    factorial(-1) == 1 ? cout << "factorial(-1):\tpassed!" << endl : cout << "factorial(-1):\tfailed..." << endl;

    abs(-10) == 10 ? cout << "abs(-10):\tpassed!" << endl : cout << "abs(-10):\tfailed... " << endl;
    abs(5) == 5 ? cout << "abs(5):\t\tpassed!" << endl : cout << "abs(5):\tfailed..." << endl;

    isLeapYear(4) == true ? cout << "isLeapYear(4):\tpassed!" << endl : cout << "isLeapYear(4):\tfailed..." << endl;
    isLeapYear(400) == true ? cout << "isLeapYear(400):\tpassed!" << endl : cout << "isLeapYear(400):\tfailed..." << endl;
    isLeapYear(300) == false ? cout << "isLeapYear(300):\tpassed!" << endl : cout << "isLeapYear(300):\tfailed..." << endl;
    isLeapYear(2000) == true ? cout << "isLeapYear(2000):\tpassed!" << endl : cout << "isLeapYear(2000):\tfailed..." << endl;

    return;
}

int main()
{
    runTests();
}