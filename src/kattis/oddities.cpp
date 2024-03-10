// https://open.kattis.com/problems/oddities

#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  getline(cin, input);
  int n = atoi(input.c_str());

  string output;

  for (int i = 0; i < n; i++) {
    getline(cin, input);
    int x = atoi(input.c_str());

    if (x % 2 == 0) {
      output += to_string(x) + " is even\n";
    } else {
      output += to_string(x) + " is odd\n";
    }
  }

  cout << output;
}