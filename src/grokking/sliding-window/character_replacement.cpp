using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class CharacterReplacement {
 public:
  static int findLength(const string& str, int k) {
    if (k >= str.size()) return str.size();
    int longest = 0, a = 0;
    unordered_map<char, int> chars{};
    for (int b = 0; b < str.size(); b++) {
      chars[str[b]]++;
      while (!CharacterReplacement::isRepeating(chars, k)) {
        chars[str[a]]--;
        if (chars[str[a]] == 0) {
          chars.erase(str[a]);
        }
        a++;
      }
      longest = max(longest, b - a + 1);
    }
    return longest;
  }

 private:
  static bool isRepeating(unordered_map<char, int> chars, int k) {
    int highest = 0, sum = 0;
    for (const auto& [_, value] : chars) {
      highest = max(highest, value);
      sum += value;
    }
    sum -= highest;
    return sum <= k;
  }
};

int main() {
  int result = CharacterReplacement::findLength("aabccbb", 2);
  cout << result << "\n";
  result = CharacterReplacement::findLength("abbcb", 1);
  cout << result << "\n";
  result = CharacterReplacement::findLength("abccde", 1);
  cout << result << "\n";
  result = CharacterReplacement::findLength("", 1);
  cout << result << "\n";
  result = CharacterReplacement::findLength("A", 1);
  cout << result << "\n";
}