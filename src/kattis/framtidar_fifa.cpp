#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  getline(cin, input);
  long long n = atoi(input.c_str());

  getline(cin, input);
  short k = atoi(input.c_str());

  std::cout << (n / k) + 2022;
}