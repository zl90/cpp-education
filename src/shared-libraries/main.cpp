#include <iostream>

#include "multiply.h"
#include "add.h"

int main()
{
    auto sum = add(10, 20);
    std::cout << "Sum: " << sum << '\n';

    auto product = multiply(10, 20);
    std::cout << "Product: " << product << '\n';

    return 0;
}