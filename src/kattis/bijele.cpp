// https://open.kattis.com/problems/bijele

#include <iostream>
#include <string>
using namespace std;

int main() {
  constexpr int ideal_piece_amounts[6] = {1, 1, 2, 2, 2, 8};
  int input_piece_amounts[6];

  string input_str;
  getline(cin, input_str);

  int input_piece_index = 0;

  for (int i = 0; i < input_str.size(); i++) {
    if (input_str[i] != ' ') {
      if (i < input_str.size() - 1 && input_str[i + 1] != ' ') {
        input_piece_amounts[input_piece_index] = 10;
        i++;
      } else {
        input_piece_amounts[input_piece_index] = (input_str[i] - '0');
      }
      input_piece_index++;
    }
  }

  for (int i = 0; i < 6; i++) {
    cout << ideal_piece_amounts[i] - input_piece_amounts[i];
    if (i < 5) {
      cout << ' ';
    }
  }
}