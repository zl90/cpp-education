using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <vector>

class GenerateParentheses {
 public:
  static vector<string> generateValidParentheses(int num) {
    if (num == 0) return {};
    vector<string> result;
    queue<string> q;
    q.push("(");
    while (!q.empty()) {
      int n = q.size();
      for (int i = 0; i < n; i++) {
        string curr = q.front();
        q.pop();
        int openParenthesisRemaining = num, closedParenthesisRemaining = num;
        for (const auto& character : curr) {
          if (character == '(') {
            openParenthesisRemaining--;
          } else {
            closedParenthesisRemaining--;
          }
        }
        if (openParenthesisRemaining > 0 && closedParenthesisRemaining > 0) {
          string newString = curr + "(";
          if (newString.size() == num * 2) {
            result.push_back(newString);
          } else {
            q.push(newString);
          }
        }
        if (openParenthesisRemaining < closedParenthesisRemaining) {
          string newString = curr + ")";
          if (newString.size() == num * 2) {
            result.push_back(newString);
          } else {
            q.push(newString);
          }
        }
      }
    }
    return result;
  }
};

int main(int argc, char* argv[]) {
  vector<string> result = GenerateParentheses::generateValidParentheses(2);
  cout << "All combinations of balanced parentheses are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;

  result = GenerateParentheses::generateValidParentheses(3);
  cout << "All combinations of balanced parentheses are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;
}
