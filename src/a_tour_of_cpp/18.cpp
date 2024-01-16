#include <thread>
#include <iostream>

void f()
{
    std::cout << "Hello ";
}

void g()
{
    std::cout << "Parallel World!\n";
}

int main()
{
    std::jthread t1{f};
    std::jthread t2{g};

    return 0;
}