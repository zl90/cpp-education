#include <vector>
#include <string>

// Using this file to test g++ compiler optimization flags

int main()
{
    auto num_elements = 1 << 28;
    std::vector<int> large_vector(num_elements);

    for (auto &item : large_vector)
    {
        item %= 20;
    }
}