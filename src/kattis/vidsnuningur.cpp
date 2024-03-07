// https://open.kattis.com/problems/vidsnuningur

#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  getline(cin, input);

  string output = "";

  for (int i = input.length() - 1; i >= 0; i--) {
    output += input[i];
  }

  cout << output;
}