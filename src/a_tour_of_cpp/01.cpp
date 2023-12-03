#include <iostream>

int main()
{
    //////// 1.6 Constants /////////
    constexpr int dmv = 17;       // dmv is a named constant.
    const double sqv = sqrt(dmv); // sqv is a named constant, possibly computed at runtime.
    constexpr double s2 = sum(v); // Error: sum(v) is not a constant expression.

    // constexpr functions:
    constexpr double square(double x) { return x * x; }

    constexpr double max1 = 1.4 * square(17);  // Okay, this is a constant expression.
    constexpr double max2 = 1.4 * square(var); // Error, var is not a constant, so can't be computed at compile time.
    const double max3 = 1.4 * square(var);     // Okay, can be computed at runtime.

    // consteval functions:
    consteval double square2(double x) { return x * x; }

    constexpr double max1 = 1.4 * square2(17); // Okay, this is a constant expression.
    const double max3 = 1.4 * square2(var);    // Error, var is not a constant.

    int y = 5;
    consteval int tripleY() { return 3 * y; } // Error, consteval functions are pure, cannot modify non-local variables.

    //////// 1.7 Pointers, arrays, and references /////////
    int *g = {56, 34, 5, 4, 88};
    for (auto &x : g)
    { // You can reference the values directly within a ranged for loop.
        ++x;
    }

    int a = 5;
    int b = 4;
    int &c = a; // References cannot be made to refer to a different object after being initialized.
    c = b;      // Watch out! `c` is now actually an alias to `a`, so this is actually putting the value of `b` into `a`.

    int a[4] = {1, 2, 3, 4};
    int *q = a;
    q++; // We can see the next element of an array by incrementing the pointer.

    std::cout << *q << '\n';
    std::cout << *++q << '\n';
    std::cout << *q++ << '\n';

    if (q) // Compares q to the negation of the nullptr --> equivalent to: if (q != nullptr).
    {
        delete q; // Error, deleting of unallocated object (since the new address wasn't allocated by new).
    }
}