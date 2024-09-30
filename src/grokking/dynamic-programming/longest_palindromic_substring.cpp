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

class Solution {
public:
  string longestPalindrome(string s) {
    if (s.length() == 0)
      return "";
    if (s.length() == 1)
      return s;
    int start = 0, end = 0;
    for (int i = 0; i < s.length(); i++) {
      // check odd sized palindromes
      int a = i, b = i;
      while (a >= 0 && b < s.length() && s[a] == s[b]) {
        if (b - a + 1 > end - start + 1) {
          start = a;
          end = b;
        }
        a--;
        b++;
      }

      // check even sized palindromes
      a = i, b = i + 1;
      while (a >= 0 && b < s.length() && s[a] == s[b]) {
        if (b - a + 1 > end - start + 1) {
          start = a;
          end = b;
        }
        a--;
        b++;
      }
    }
    string output = "";
    for (int i = start; i <= end; i++) {
      output += s[i];
    }
    return output;
  }
};