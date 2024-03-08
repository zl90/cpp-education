// https://open.kattis.com/problems/umferd

#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  getline(cin, input);
  int m = atoi(input.c_str());
  getline(cin, input);
  int n = atoi(input.c_str());

  double empty_count = 0;

  for (int i = 0; i < n; i++) {
    getline(cin, input);

    for (int j = 0; j < m; j++) {
      if (input[j] == '.') {
        empty_count++;
      }
    }
  }

  cout << empty_count / (n * m);
}