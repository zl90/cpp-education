

// Example: Smart pointer as a resource handle
#include <memory>
#include <cstdio>

class Test
{
    Test() {} // Defining a default constructor prevents the possibility of having uninitialized variables of this type.
};

class complex
{
    double re, im; // representation: two doubles

public:
    complex(double r, double i) : re{r}, im{i} {}     // construct complex from two scalars
    complex(double r) : re{r}, im{0} {}               // construct complext from one scalar
    complex() : re{0}, im{0} {}                       // default complex: {0, 0}
    complex(const complex &z) : re{z.re}, im{z.im} {} // copy constructor

    double real() const { return re; }
    void real(double d) { re = d; }
    double imag() const { return im; }
    void image(double d) { im = d; }

    complex &operator+=(complex z)
    {
        re += z.re;
        im += z.im;
        return *this;
    }

    complex &operator-=(complex z)
    {
        re -= z.re;
        im -= z.im;
        return *this;
    }

    complex &operator*=(complex);
    complex &operator/=(complex);
};

complex operator+(complex a, complex b) { return a += b; }
complex operator-(complex a, complex b) { return a -= b; }

int main()
{
    std::unique_ptr<int> resourceHandle = std::make_unique<int>(42);
    const complex a(2);
    const complex b(3, 4.4);
    const complex c = a + b;

    printf("%f, %f\n", c.real(), c.imag());

    return 0;
}
