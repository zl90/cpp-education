#include <iostream>
#include <string>

using namespace std;

int main() {
  string input;
  getline(cin, input);

  int n = atoi(input.c_str());

  getline(cin, input);

  int m = atoi(input.c_str());

  std::cout << n % m;
}