#include <iostream>
#include <string>
#include <concepts>

template <typename T>
class Vector
{
    T *elements;
    int size;

public:
    explicit Vector(int a)
    { // constructor
        elements = new T[a];
        size = a;
    }

    explicit Vector(int a, T x)
    { // constructor
        elements = new T[a];
        size = a;

        for (int i = 0; i < size; i++)
        {
            elements[i] = x;
        }
    }

    ~Vector()
    { // destructor
        delete[] elements;
    }

    Vector<T>(const Vector<T> &obj)
    { // copy constructor
        size = obj.size;
        elements = new T[size];

        for (int i = 0; i < size; i++)
        {
            elements[i] = obj.elements[i];
        }
    }

    Vector<T> &operator=(const Vector<T> &obj)
    { // copy assignment operator override
        if (size > 0)
        {
            delete[] elements;
        }
        size = obj.size;
        elements = new T[size];

        for (int i = 0; i < size; i++)
        {
            elements[i] = obj.elements[i];
        }
        std::cout << "Copy assignment operator called!\n";
        return *this;
    }

    Vector<T>(Vector<T> &&obj)
    { // move constructor
        if (size > 0)
        {
            delete[] elements;
        }
        size = obj.size;
        elements = obj.elements;
        obj.size = 0;
        obj.elements = nullptr;
        std::cout << "Move constructor called!\n";
    }

    Vector<T> &operator=(Vector<T> &&obj) noexcept
    { // move assignment operator
        if (this != &obj)
        {
            delete[] elements;

            size = obj.size;
            elements = obj.elements;

            obj.size = 0;
            obj.elements = nullptr;

            std::cout << "Move assignment operator called!\n";
        }
        return *this;
    }

    T &operator[](int i)
    { // array subscript overload
        return elements[i];
    }

    const T &operator[](int i) const
    { // array subscript overload
        return elements[i];
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << elements[i] << ", ";
        }

        std::cout << '\n';
    }

    int get_size() const { return size; }
};

template <typename T>
T *begin(Vector<T> &x)
{ // iterator. This returns a pointer because the elements are allocated on the heap.
    return &x[0];
}

template <typename T>
T *end(Vector<T> &x)
{                                // iterator
    return &x[0] + x.get_size(); // point to one past the last element of the vector
}

template <typename T>
T *begin(const Vector<T> &x)
{ // iterator. This returns a pointer because the elements are allocated on the heap.
    return &x[0];
}

template <typename T>
T *end(const Vector<T> &x)
{                                // iterator
    return &x[0] + x.get_size(); // point to one past the last element of the vector
}

template <typename T>
Vector<T> operator+(const Vector<T> &a, const Vector<T> &b)
{ // operator overload
    if (a.get_size() != b.get_size())
    {
        throw "Vector size mismatch";
    }

    Vector<T> result(a.get_size());

    for (int i = 0; i < a.get_size(); i++)
    {
        result[i] = a[i] + b[i];
    }

    return result;
}

template <typename T>
Vector<T> operator-(const Vector<T> &a, const Vector<T> &b)
{
    if (a.get_size() != b.get_size())
    {
        throw "Vector size mismatch";
    }

    Vector<T> result(a.get_size());

    for (int i = 0; i < a.get_size(); i++)
    {
        result[i] = a[i] - b[i];
    }

    return result;
}

template <typename A>
concept Equality_comparable =
    requires(A a, A b) { {a == b} -> std::__boolean_testable; { a != b } -> std::__boolean_testable; };

template <typename A, typename B = A>
concept Number =
    requires(A x, B y) {
        x + y;
        x - y;
        x *y;
        x / y;
        x += y;
        x -= y;
        x *= y;
        x /= y;
        x = x;
        x = 0;
    };

template <typename A, typename B = A>
concept Arithmetic = Number<A, B> && Number<B, A>;

template <typename A, typename Functor>
    requires Equality_comparable<A> && Number<A>
auto map(const Vector<A> &v, Functor &&f)
{
    using B = std::invoke_result_t<Functor, A>; // Deduce return type at runtime
    Vector<B> result(v.get_size());

    for (int i = 0; i < v.get_size(); i++)
    {
        result[i] = f(v[i]);
    }

    return result;
}

auto twice(Number auto x) { return x + x; }

double sum(const Vector<double> &v)
{
    double result = 0;

    for (auto x : v)
    {
        result += x;
    }

    return result;
}

// Convert the above function into a generic function:
template <std::forward_iterator Iter, Arithmetic<std::iter_value_t<Iter>> Val>
Val accumulate(Iter first, Iter last, Val accumulator)
{
    for (auto p = first; p != last; ++p)
    {
        accumulator += *p;
    }

    return accumulator;
}

int main()
{
    Vector<double> v(5, 1);
    v.print();

    Vector<double> v2(v);
    Vector<double> v3 = v2;

    v2.print();
    v3.print();

    v2 = v;
    Vector<double> v4 = v2 + v3;
    v4 = v2 + v2 + v3;
    v4.print();

    Vector<double> v5 = v4 - v4;

    for (auto &x : v4) // Use a ranged for loop over a Vector, thanks to the begin() and end() functions.
    {
        std::cout << x << ". ";
    }
    std::cout << '\n';

    v5.print();

    Vector<char> v6(5, 'x');

    v6.print();

    Vector<int> v7 = map(v6, [](const char &a)
                         { int b = a; return b + 1; }); // Use a lambda as a functor in a higher order function.

    v7.print();
    // int sum_v7 = accumulate(begin(v7), end(v7), 0);

    std::string s = "Hello";
    // auto x2 = twice(s); // Causes error, string does not satisfy the Number concept.
    int a = 44;
    auto x3 = twice(a); // Works fine, int is a Number.

    return 0;
}
