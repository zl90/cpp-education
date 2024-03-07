// https://open.kattis.com/problems/tolvunarfraedingartelja

#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  getline(cin, input);
  int n = atoi(input.c_str());

  cout << n - 1;
}