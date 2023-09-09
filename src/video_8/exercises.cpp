#include "../test_utils.h"
#include <iostream>
#include <string>

using namespace std;

string HelloMessage()
{
    return "Hello";
}

string Goodbye()
{
    return "Goodbye";
}

string Message(const string input)
{
    return input;
}

// Exercise 4: passing a comparison function as a parameter to a sorting algorithm:
// Note to self: this will come in useful when I attempt to do CS19 in C++
string Sort(int *numbers, int size, bool (*comparison)(int, int))
{
    for (int n = 0; n < size; n++)
    {
        int nBestIndex = n;
        for (int i = n + 1; i < size; i++)
        {
            if (comparison(numbers[i], numbers[nBestIndex]))
            {
                nBestIndex = i;
            }
        }
        swap(numbers[n], numbers[nBestIndex]);
    }

    string result;

    for (int i = 0; i < size; i++)
    {
        result += to_string(numbers[i]) + " ";
    }

    return result;
}

bool Ascending(int nX, int nY)
{
    return nY > nX;
}

bool Descending(int nX, int nY)
{
    return nY <= nX;
}

void runTests()
{
    string (*helloPtr)() = HelloMessage;
    string (*goodbyePtr)() = Goodbye;
    const string input = "Microsoft";
    string (*messagePtr)(const string) = Message;

    expect("Test1", helloPtr(), "Hello");
    expect("Test2", goodbyePtr(), "Goodbye");
    expect("Test3", messagePtr(input), input);
    expect("Test4", messagePtr("Google"), "Google");

    int *unsorted;
    unsorted = new int[5];
    unsorted[0] = 3;
    unsorted[1] = 1;
    unsorted[2] = 2;
    unsorted[3] = 8;
    unsorted[4] = 5;

    expect("Test5", Sort(unsorted, 5, Ascending), "1 2 3 5 8 ");
    expect("Test6", Sort(unsorted, 5, Descending), "8 5 3 2 1 ");
}

int main()
{
    runTests();

    return 0;
}