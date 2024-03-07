// https://open.kattis.com/problems/quadrant

#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  getline(cin, input);
  int x = atoi(input.c_str());
  getline(cin, input);
  int y = atoi(input.c_str());

  if (x > 0) {
    if (y > 0) {
      cout << 1;
    } else {
      cout << 4;
    }
  } else {
    if (y > 0) {
      cout << 2;
    } else {
      cout << 3;
    }
  }
}