#include <thread>
#include <iostream>
#include <vector>
#include <mutex>
#include <chrono>
#include <future>

static int count = 0;

std::mutex m;

void f()
{
    std::scoped_lock lock{m}; // Acquire mutex
    count = count + 1;
} // Mutex is implicitly released when lock is destructed

int factorial(int N)
{
    if (N <= 1)
    {
        return 1;
    }
    else
    {
        return N * factorial(N - 1);
    }
}

int square(int x)
{
    return x * x;
}

int main()
{
    // Making a thousand threads (note: without a mutex and a thread lock, the results of the following code is non-deterministic):
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

    // Waiting inside a thread:
    auto t0 = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    auto t1 = std::chrono::high_resolution_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count() << " nanoseconds passed\n";

    // Using async and future:
    std::future<int> asyncFunction = std::async(&square, 12); // Does the async function spawn a new thread?? --> Depends on the launch policy.
    auto result = asyncFunction.get();                        // .get() is a blocking operation

    std::cout << "Result is: " << result << '\n';

    // Using std::packaged_task:
    std::packaged_task<int(int)> pt(factorial);

    pt(10); // packaged_tasks can be used later
    int pt_result = pt.get_future().get();

    std::cout << "Result of packaged task: " << pt_result << '\n';

    return 0;
}