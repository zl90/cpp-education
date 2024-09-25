class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    if (s.length() == 0 || wordDict.size() == 0)
      return false;
    for (int i = 0; i < wordDict.size(); i++) {
      while (true) {
        // find instance of current word, recording where it is
        int start = 0, end = 0;
        bool wordExists = false;
        bool isInsidePossibleWord = false;
        for (int j = 0; j < s.length(); j++) {
          if (s[j] == wordDict[i][0] && !isInsidePossibleWord) {
            isInsidePossibleWord = true;
            start = j;
            if (s[j] == wordDict[i][wordDict[i].length() - 1]) {
              wordExists = true;
              end = j;
              break;
            }
          } else if (isInsidePossibleWord) {
            if (s[j] == wordDict[i][wordDict[i].length() - 1]) {
              wordExists = true;
              end = j;
              break;
            } else if (s[j] != wordDict[i][j - start]) {
              isInsidePossibleWord = false;
            }
          }
        }

        if (wordExists) {
          // if there is an instance, remove it from s
          string temp = "";
          for (int j = 0; j < s.length(); j++) {
            if (j < start || j > end) {
              temp += s[j];
            }
          }
          s = temp;
        } else {
          // otherwise break, check next word in dict
          break;
        }
      }
    }
    return s == "";
  }
};