// https://open.kattis.com/problems/twostones

#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  getline(cin, input);
  int n = atoi(input.c_str());

  if (n % 2 == 0) {
    cout << "Bob";
  } else {
    cout << "Alice";
  }
}