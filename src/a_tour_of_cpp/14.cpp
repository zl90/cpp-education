// Chapter 14: Ranges

#include <ranges>
#include <string>
#include <iostream>
#include <vector>
#include <string_view>

int main()
{
    // Using Generators:
    for (int x : std::ranges::iota_view(42, 55))
    {
        std::cout << x << ", ";
    }

    std::cout << "\n";

    return 0;
}