#include <array>
#include <iostream>

// Running this program with Valgrind will demonstrate an `accessing uninitialized memory` error

int main()
{
    std::array<int, 5> my_array = {42, 3, 39, 4, 9};

    // A for loop with an off-by-one error
    for (auto i = 0u; i <= my_array.size(); i++)
    {
        std::cout << my_array[i] << '\n';
    }

    return 0;
}