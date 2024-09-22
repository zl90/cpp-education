class Solution {
public:
  string longestPalindrome(string s) {
    int longest = 0;
    string result = "";
    for (int i = 0; i < s.size(); i++) {
      // handle odd sized palindromes
      int left = i, right = i;
      while (left >= 0 && right < s.size() && s[left] == s[right]) {
        if (right - left + 1 > longest) {
          longest = right - left + 1;
          result = s.substr(left, longest);
        }
        left--;
        right++;
      }

      // handle even sized palindromes
      left = i, right = i + 1;
      while (left >= 0 && right < s.size() && s[left] == s[right]) {
        if (right - left + 1 > longest) {
          longest = right - left + 1;
          result = s.substr(left, longest);
        }
        left--;
        right++;
      }
    }
    return result;
  }
};