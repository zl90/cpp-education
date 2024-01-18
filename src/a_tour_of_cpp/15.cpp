#include <array>
#include <bitset>
#include <iostream>
#include <memory>
#include <variant>

// unique_ptr
std::unique_ptr<int> make_int(int i) {
  return std::unique_ptr<int>{new int(i)};
}

struct S {
  int i;
  std::string s;
  double d;
};

void fs(std::span<int> p) {
  for (int &x : p) {
    x = 0;
  }
}

void use(int x) {
  int a[100];
  fs(a); // implicitly creates a span<int>{a, 100}
         // fs(a, 1000);       // Error: span expected
         // fs({a + 10, 100}); // a range error in fs
         // fs({a, x}); // suspect
}

std::variant<std::string, int> compose_message(std::istream &is) {
  std::string result;

  if (is >> result) {
    return result;
  } else {
    return -1; // error code
  }
}

int main() {
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

  // Using std::arrays
  std::array<int, 3> a1 = {1, 2, 3};
  auto a2 = a1; // std::arrays can be copied.
  a2[1] = 5;
  a1 = a2; // std::arrays can be assigned.

  // Using bitsets:
  std::bitset<9> bs1{"110001111"};
  std::bitset<9> bs2{0b1'1000'1111};

  std::bitset<9> bs3 = ~bs1;      // complement
  std::bitset<9> bs4 = bs1 & bs3; // all zeros
  std::bitset<9> bs5 = bs1 << 2;  // shift left

  std::cout << bs1 << '\n';
  std::cout << bs2 << '\n';
  std::cout << bs3 << '\n';
  std::cout << bs4 << '\n';
  std::cout << bs5 << '\n';
  std::cout << bs5.flip() << '\n';
  std::cout << bs5.flip().count() << '\n';

  // Using Variants:
  auto possible_error = compose_message(std::cin);

  if (std::holds_alternative<std::string>(possible_error)) {
    std::cout << std::get<std::string>(possible_error) << '\n';
  } else {
    auto error = std::get<int>(possible_error);
    std::cerr << "Error code: " << error << '\n';
  }

  return 0;
}