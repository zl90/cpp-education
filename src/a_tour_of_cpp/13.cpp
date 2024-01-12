#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iterator>

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

bool operator<(const Entry &a, const Entry &b)
{
    return a.name < b.name;
}

bool operator==(const Entry &a, const Entry &b)
{
    return a.name == b.name && a.number == b.number;
}

std::list<Entry> copy_vector_to_list(std::vector<Entry> &vec, std::list<Entry> &lst)
{
    std::list<Entry> result;
    std::sort(vec.begin(), vec.end());
    std::unique_copy(vec.begin(), vec.end(), std::back_inserter(result));

    return result;
}

template <typename Container>
void print_container(const Container &v)
{
    for (const auto &x : v)
    {
        std::cout << x << '\n';
    }
}

bool has_c(const std::string &s, const char &c)
{
    auto p = std::find(s.begin(), s.end(), c);

    return p != s.end();
}

int main()
{
    // Exploring the relationship between algorithms, iterators and containers:
    std::vector<Entry> v = {{"john", 1}, {"john", 1}, {"fred", 2}};
    std::list<Entry> l = copy_vector_to_list(v, l);

    print_container(v);
    std::cout << '\n';
    print_container(l);

    std::cout << has_c("asdfg", 'g') << '\n';
    std::cout << has_c("asdfg", 'n') << '\n';

    // Using stream iterators:
    std::ostream_iterator<std::string> oi{std::cout};

    *oi = "Hello, "; // Same as cout << "Hello, "
    ++oi;
    *oi = "world!\n"; // Same as cout << "world!\n"

    return 0;
}