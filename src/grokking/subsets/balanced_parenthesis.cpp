using namespace std;

#include <deque>
#include <iostream>
#include <string>
#include <vector>

class BalancedParenthesis {
 public:
  static bool isBalancedParenthesis(const string& str) {
    if (str.size() == 0) return false;
    if (str.size() % 2 != 0) return false;
    deque<char> stack;
    for (const char& character : str) {
      if (character == '(') {
        stack.push_front(character);
      } else {
        if (stack.empty()) {
          return false;
        } else {
          stack.pop_front();
        }
      }
    }
    return stack.empty();
  }
};

int main(int argc, char* argv[]) {
  string testString = "((()))";
  bool result = BalancedParenthesis::isBalancedParenthesis(testString);
  cout << testString << " is balanced: " << result << "\n";
  testString = "(())()";
  result = BalancedParenthesis::isBalancedParenthesis(testString);
  cout << testString << " is balanced: " << result << "\n";
  testString = "()(())";
  result = BalancedParenthesis::isBalancedParenthesis(testString);
  cout << testString << " is balanced: " << result << "\n";
  testString = "(()())";
  result = BalancedParenthesis::isBalancedParenthesis(testString);
  cout << testString << " is balanced: " << result << "\n";
  testString = "()()()";
  result = BalancedParenthesis::isBalancedParenthesis(testString);
  cout << testString << " is balanced: " << result << "\n";
}
