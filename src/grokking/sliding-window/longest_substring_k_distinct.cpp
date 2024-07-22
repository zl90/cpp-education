using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class LongestSubstringKDistinct {
 public:
  static int findLength(const string &str, int k) {
    if (str.size() == 0 || str.size() == 1) return str.size();

    unordered_map<char, int> characters{};
    int longest = 0, a = 0;

    for (int b = 0; b < str.size(); b++) {
      if (characters[str[b]]) {
        characters[str[b]]++;
      } else {
        characters[str[b]] = 1;
      }
      while (characters.size() > k) {
        characters[str[a]]--;
        if (characters[str[a]] == 0) {
          characters.erase(str[a]);
        }
        a++;
      }
      longest = max(longest, b - a + 1);
    }

    return longest;
  }
};

int main() {
  int result = LongestSubstringKDistinct::findLength("araaci", 2);
  std::cout << result << "\n";
  result = LongestSubstringKDistinct::findLength("araaci", 1);
  std::cout << result << "\n";
  result = LongestSubstringKDistinct::findLength("cbbebi", 3);
  std::cout << result << "\n";
}