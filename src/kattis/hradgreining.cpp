// https://open.kattis.com/problems/hradgreining

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string substr = "COV";
  string input;
  getline(cin, input);

  bool contains_substr = false;

  for (int i = 0; i < input.size(); i++) {
    if (input[i] == substr[0] && input.size() - i >= substr.length()) {
      contains_substr = true;
      for (int j = 1; j < substr.length(); j++) {
        if (input[i + j] == substr[j]) {
          continue;
        } else {
          contains_substr = false;
          break;
        }
      }

      if (contains_substr) {
        break;
      }
    }
  }

  if (contains_substr) {
    cout << "Veikur!";
  } else {
    cout << "Ekki veikur!";
  }
}