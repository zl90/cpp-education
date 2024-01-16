#include <thread>
#include <iostream>
#include <vector>
#include <mutex>

static int count = 0;

std::mutex m;

void f()
{
    std::scoped_lock lock{m}; // Acquire mutex
    count = count + 1;
} // Mutex is implicitly released when lock is destructed

int main()
{
    for (int j = 0; j < 20; j++)
    {
        std::vector<std::thread> threads;

        for (int i = 0; i < 1000; i++)
        {
            threads.push_back(std::thread(f));
        }

        for (int i = 0; i < 1000; i++)
        {
            threads[i].join();
        }

        std::cout << "Count: " << count << '\n';
        count = 0;
    }

    return 0;
}