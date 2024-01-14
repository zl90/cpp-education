#include <iostream>
#include <vector>
#include <memory>

// unique_ptr
std::unique_ptr<int> make_int(int i)
{
    return std::unique_ptr<int>{new int(i)};
}

struct S
{
    int i;
    std::string s;
    double d;
};

int main()
{
    std::unique_ptr<int> i = make_int(14);
    std::cout << *i << '\n';

    std::shared_ptr<int> i_shared{new int(54)};
    std::shared_ptr<int> i_shared_2 = i_shared;

    std::cout << *i_shared << '\n';
    std::cout << *i_shared_2 << '\n';

    // Using make_shared and make_unique:
    auto p1 = std::make_shared<S>(1, "Ankh Morpork", 4.65);
    auto p2 = std::make_unique<S>(2, "Oz", 7.62);

    return 0;
}