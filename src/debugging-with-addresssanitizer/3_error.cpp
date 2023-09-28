#include <algorithm>
#include <random>
#include <iostream>

// Running this program with Valgrind will demonstrate a `use after free` error

int main()
{
    int N = 1 << 10;
    float *a = new float[N];
    float *b = new float[N];

    // Create random number generator
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution dist(0.0f, 1.0f);

    // Generate some random numbers
    std::generate(a, a + N, [&]
                  { return dist(mt); });
    std::generate(b, b + N, [&]
                  { return dist(mt); });

    // Do vector addition
    for (int i = 0; i < N; i++)
    {
        a[i] = a[i] + b[i];
    }

    // Free the memory
    delete[] a;
    delete[] b;

    // Read memory after is has been freed
    std::cout << a[0] << '\n';
    std::cout << b[0] << '\n';

    return 0;
}