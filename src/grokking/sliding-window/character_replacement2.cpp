using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class CharacterReplacement {
 public:
  static int findLength(const string& str, int k) {
    if (str.size() == 0) return 0;
    if (str.size() <= k) return str.size();
    int a = 0, longest = 0, highestFreq = 0;
    unordered_map<char, int> frequencies;
    for (int b = 0; b < str.size(); b++) {
      frequencies[str[b]]++;
      highestFreq = max(highestFreq, frequencies[str[b]]);
      while ((b - a + 1) - highestFreq > k) {
        frequencies[str[a]]--;
        a++;
      }
      longest = max(longest, b - a + 1);
    }
    return longest;
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
  result = CharacterReplacement::findLength("abc", 5);
  cout << result << "\n";
}