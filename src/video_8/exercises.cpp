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
}

int main()
{
    runTests();

    return 0;
}