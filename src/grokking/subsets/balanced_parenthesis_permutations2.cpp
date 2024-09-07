
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class GenerateParentheses {
 public:
  static vector<string> generateValidParentheses(int num) {
    if (num <= 0) return {};
    vector<string> result;
    dfs("(", 1, 0, result, num);
    return result;
  }

 private:
  static void dfs(string str, int openCount, int closedCount,
                  vector<string>& output, int N) {
    if (openCount < closedCount || openCount > N || closedCount > N) return;
    if (str.size() == N * 2) {
      output.push_back(str);
      return;
    }
    dfs(str + "(", openCount + 1, closedCount, output, N);
    dfs(str + ")", openCount, closedCount + 1, output, N);
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
