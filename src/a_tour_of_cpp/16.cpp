#include <chrono>
#include <iostream>

int main()
{
    // Tracking time with std::chrono:
    auto t0 = std::chrono::system_clock::now();
    for (int i = 0; i < 100000000; i++)
    {
        int j = 55;
    }
    auto t1 = std::chrono::system_clock::now();

    // std::cout << t1 - t0 << '\n';
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count() << "ms\n";
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count() << "ns\n";

    return 0;
}