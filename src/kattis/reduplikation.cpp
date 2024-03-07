// https://open.kattis.com/problems/reduplikation

#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  getline(cin, input);
  string s = input;
  getline(cin, input);
  int n = atoi(input.c_str());
  for (int i = 0; i < n; i++) {
    cout << s;
  }
}