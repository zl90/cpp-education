class Solution {
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