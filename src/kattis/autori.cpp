// https://open.kattis.com/problems/autori

#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  getline(cin, input);
  string output;

  output += input[0];

  bool next_char_is_capitalized = false;
  for (int i = 1; i < input.size(); i++) {
    if (next_char_is_capitalized) {
      output += input[i];
      next_char_is_capitalized = false;
      continue;
    }

    if (input[i] == '-') {
      next_char_is_capitalized = true;
    }
  }

  cout << output;
}