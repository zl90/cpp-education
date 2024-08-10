using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <vector>

class LetterCaseStringPermutation {
 public:
  static vector<string> findLetterCaseStringPermutations(const string& str) {
    vector<string> permutations;
    queue<string> q;
    q.push("");
    for (const char& character : str) {
      int n = q.size();
      for (int i = 0; i < n; i++) {
        string curr = q.front();
        q.pop();
        if (isLowerCaseLetter(character)) {
          if ((curr + character).size() == str.size()) {
            permutations.push_back(curr + character);
            permutations.push_back(curr + static_cast<char>(character - 32));
          } else {
            q.push(curr + character);
            q.push(curr + static_cast<char>(character - 32));
          }
        } else if (isUpperCaseLetter(character)) {
          if ((curr + character).size() == str.size()) {
            permutations.push_back(curr + character);
            permutations.push_back(curr + static_cast<char>(character + 32));
          } else {
            q.push(curr + character);
            q.push(curr + static_cast<char>(character + 32));
          }
        } else {
          if ((curr + character).size() == str.size()) {
            permutations.push_back(curr + character);
          } else {
            q.push(curr + character);
          }
        }
      }
    }
    return permutations;
  }

 private:
  static bool isLowerCaseLetter(const char& c) { return c > 96 && c < 123; }

  static bool isUpperCaseLetter(const char& c) { return c > 64 && c < 91; }
};

int main(int argc, char* argv[]) {
  vector<string> result =
      LetterCaseStringPermutation::findLetterCaseStringPermutations("ad52");
  cout << "String permutations are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;

  result =
      LetterCaseStringPermutation::findLetterCaseStringPermutations("ab7c");
  cout << "String permutations are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;
}
