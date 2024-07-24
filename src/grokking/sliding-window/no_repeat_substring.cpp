using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class NoRepeatSubstring {
 public:
  static int findLength(const string& str) {
    if (str.size() == 0 || str.size() == 1) return str.size();

    int longest = 0, a = 0;
    unordered_map<char, int> chars{};
    for (int b = 0; b < str.size(); b++) {
      if (chars[str[b]]) {
        chars[str[b]]++;
      } else {
        chars[str[b]] = 1;
      }
      while (isRepeating(chars)) {
        chars[str[a]]--;
        if (chars[str[a]] == 0) chars.erase(str[a]);
        a++;
      }
      longest = max(longest, b - a + 1);
    }

    return longest;
  }

 private:
  static bool isRepeating(unordered_map<char, int> chars) {
    for (const auto& [_, value] : chars) {
      if (value > 1) return true;
    }
    return false;
  }
};

int main() {
  int result = NoRepeatSubstring::findLength("aabccbb");
  cout << result << "\n";
  result = NoRepeatSubstring::findLength("abbbb");
  cout << result << "\n";
  result = NoRepeatSubstring::findLength("abccde");
  cout << result << "\n";
  result = NoRepeatSubstring::findLength("");
  cout << result << "\n";
  result = NoRepeatSubstring::findLength("A");
  cout << result << "\n";
}