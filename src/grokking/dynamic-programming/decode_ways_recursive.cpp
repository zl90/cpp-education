class Solution {
public:
  int numDecodings(string s) { return dfs(0, s); }

private:
  int dfs(int i, string s) {
    int size = s.size() - i;
    if (size == 0)
      return 1;
    if (size == 1) {
      if (s[i] != '0') {
        return 1;
      } else {
        return 0;
      }
    }
    int smaller = s[i] - '0', larger = ((s[i] - '0') * 10) + (s[i + 1] - '0');
    if (smaller == 0)
      return 0;
    if (larger < 1 || larger > 26)
      return dfs(i + 1, s);
    return dfs(i + 1, s) + dfs(i + 2, s);
  }
};