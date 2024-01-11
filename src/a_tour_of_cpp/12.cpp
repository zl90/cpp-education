// Chapter 12: Containers
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

struct Entry
{
    std::string name;
    int number;

    friend std::ostream &operator<<(std::ostream &oss, const Entry &entry)
    {
        oss << entry.name << ",\t" << entry.number;
        return oss;
    }
};

template <typename T>
void print_vector(const std::vector<T> &v)
{
    for (const auto &x : v)
    {
        std::cout << x << '\n';
    }
}

class A
{
public:
    int foo = 0;
};

class B : public A
{
public:
    int bar = 1;
};

int main()
{
    // Vectors
    std::vector<Entry> phone_book = {{"john", 234234}, {"fred", 2345425}, {"tim", 345435}};
    print_vector(phone_book);

    std::vector<Entry *> v(6); // size is 6, initial element value: nullptr
    print_vector(v);

    std::vector<double> v2(6, 9.9); // size is 6, initial element values are: 9.9
    print_vector(v2);

    B b;
    A a = b;             // Object slicing!
    const int g = a.foo; // Note: `a` doesn't contain the `bar` member as it has been "sliced" away.

    // using the ::at() function:
    std::cout << "Element at index 1: " << phone_book.at(1) << '\n';
    try
    {
        std::cout << "Element at index 5 (out of bounds): " << phone_book.at(5) << '\n'; // This will throw because .at() does range-checking!
    }
    catch (std::out_of_range ex)
    {
        std::cout << "Caught the out of bounds error!: " << ex.what() << '\n';
    }

    return 0;
}