#include <iostream>
#include <vector>
#include <memory>
#include <span>

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

void fs(std::span<int> p)
{
    for (int &x : p)
    {
        x = 0;
    }
}

void use(int x)
{
    int a[100];
    fs(a); // implicitly creates a span<int>{a, 100}
    // fs(a, 1000);       // Error: span expected
    // fs({a + 10, 100}); // a range error in fs
    // fs({a, x}); // suspect
}

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

    use(45);

    return 0;
}