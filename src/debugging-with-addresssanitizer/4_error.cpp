#include <algorithm>
#include <random>
#include <iostream>

// Running this program with Valgrind will demonstrate a `reading uninitialized values` error

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
    // (purposefully don't initialise)
    std::generate(a, a + N - 1, [&]
                  { return dist(mt); });
    std::generate(b, b + N - 1, [&]
                  { return dist(mt); });

    // Do vector addition
    for (int i = 0; i < N; i++)
    {
        a[i] = a[i] + b[i];
    }

    // Print the final result
    std::cout << a[N - 1] << '\n';

    // Free the memory
    delete[] a;
    delete[] b;

    return 0;
}