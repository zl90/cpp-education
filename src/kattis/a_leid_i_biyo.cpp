// https://open.kattis.com/problems/aleidibio

#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  getline(cin, input);

  int a = atoi(input.c_str());

  getline(cin, input);

  int b = atoi(input.c_str());

  getline(cin, input);

  int c = atoi(input.c_str());

  cout << c - a - b;
}