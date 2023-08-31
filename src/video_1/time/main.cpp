#include <ctime>
#include <iostream>
using namespace std;

int main()
{
    time_t now = time(NULL);
    cout << now << endl;

    return 0;
}