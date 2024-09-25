class SolutionRecursive {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    bool isValid = false;
    for (int i = 0; i < wordDict.size(); i++) {
      if (dfs(s, 0, wordDict, wordDict[i])) isValid = true;
    }
    return isValid;
  }

  bool dfs(string s, int i, vector<string> wordDict, string currWord) {
    int size = s.size() - i;
    if (size <= 0) return true;
    if (currWord.size() > size) return false;
    for (int j = 0; j < currWord.size(); j++) {
      if (currWord[j] != s[i + j]) return false;
    }
    bool isValid = false;
    for (int j = 0; j < wordDict.size(); j++) {
      if (dfs(s, i + currWord.size(), wordDict, wordDict[j])) isValid = true;
    }
    return isValid;
  }
};

class SolutionBottomUp {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> valid(s.size(), false);
    for (int i = s.size() - 1; i >= 0; i--) {
      int remainingSize = s.size() - i;
      for (int j = 0; j < wordDict.size(); j++) {
        if (remainingSize >= wordDict[j].size()) {
          bool possiblePath = true;
          for (int k = 0; k < wordDict[j].size(); k++) {
            if (wordDict[j][k] != s[i + k]) {
              possiblePath = false;
              break;
            }
          }
          if (possiblePath && (i + wordDict[j].size() == s.size() ||
                               valid[i + wordDict[j].size()])) {
            valid[i] = true;
          }
        }
      }
    }
    return valid[0];
  }
};