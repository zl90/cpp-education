#include <iostream>
#include <string>

using namespace std;

const int MAXIMUM_HEALTH = 100;

int main()
{
    string name = "zl90";
    char firstLetter = name[0];
    cout << "Name: " << name << endl;
    cout << "First letter: " << firstLetter << endl;
    cout << "Health: " << MAXIMUM_HEALTH << endl;

    return 0;
}