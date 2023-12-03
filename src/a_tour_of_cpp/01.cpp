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
}