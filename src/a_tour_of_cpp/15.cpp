#include <iostream>
#include <vector>
#include <memory>

// unique_ptr
std::unique_ptr<int> make_int(int i)
{
    return std::unique_ptr<int>{new int(i)};
}

int main()
{
    std::unique_ptr<int> i = make_int(14);
    std::cout << *i << '\n';

    return 0;
}