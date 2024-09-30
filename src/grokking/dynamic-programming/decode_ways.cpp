class SolutionRecursive {
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

#include <cstdlib>
class SolutionDP {
public:
  int numDecodings(string s) {
    int a = 0, b = 1;
    if (s[s.size() - 1] != '0') {
      a = 1;
    }
    for (int i = s.size() - 2; i >= 0; i--) {
      int curr = s[i] - '0';
      int next = (curr * 10) + (s[i + 1] - '0');
      int c = 0;
      if (curr >= 1 && next >= 1 && next <= 26) {
        c = a + b;
      } else if (curr >= 1) {
        c = b;
      }
      b = a;
      a = c;
    }
    return a;
  }
};