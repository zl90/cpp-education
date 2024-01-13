#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <execution>

struct Entry
{
    std::string name;
    int number;

    friend std::ostream &operator<<(std::ostream &oss, const Entry &entry)
    {
        oss << "{\"" << entry.name << ", " << entry.number << "\"}";
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
        std::cout << x << ", ";
    }

    std::cout << '\n';
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
    print_container(l);

    std::cout << has_c("asdfg", 'g') << '\n';
    std::cout << has_c("asdfg", 'n') << '\n';

    // Using stream iterators:
    std::ostream_iterator<std::string> oi{std::cout};

    *oi = "Hello, "; // Same as cout << "Hello, "
    ++oi;
    *oi = "world!\n"; // Same as cout << "world!\n"

    // Parallel and vectorized execution of algorithms:
    std::vector<int> vi = {5, 6, 1, 0, -45, 8, 9, 3, 6};
    std::vector<int> vii = {5, 6, 1, 0, -45, 8, 9, 3, 6};
    std::vector<int> viii = {5, 6, 1, 0, -45, 8, 9, 3, 6};

    std::sort(std::execution::seq, vi.begin(), vi.end());           // sequential (same as default)
    std::sort(std::execution::par, vii.begin(), vii.end());         // parallel
    std::sort(std::execution::par_unseq, viii.begin(), viii.end()); // parallel and/or vectorized

    print_container(vi);
    print_container(vii);
    print_container(viii);

    return 0;
}