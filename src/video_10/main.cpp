
#include <thread>
#include <iostream>
#include <string>
#include <chrono>

using namespace std;

void threadCallable(int sleepTimeInSeconds)
{
    cout << "Start of thread" << endl;
    this_thread::sleep_for(chrono::seconds(sleepTimeInSeconds));
    cout << "End of thread" << endl
         << flush;
}

int main()
{
    thread thread1(threadCallable, 1);
    thread1.join();

    return 0;
}