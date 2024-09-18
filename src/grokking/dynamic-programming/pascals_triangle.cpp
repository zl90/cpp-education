class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    if (numRows == 0)
      return {};
    vector<vector<int>> result = {{1}};
    for (int i = 1; i < numRows; i++) {
      int a = 0, b = 1;
      vector<int> prev = result.back();
      vector<int> curr;
      for (int j = 0; j < i; j++) {
        curr.push_back(a + b);
        a = b;
        if (j == i - 1) {
          b = 0;
        } else {
          b = prev[j + 1];
        }
      }
      curr.push_back(a + b);
      result.push_back(curr);
    }
    return result;
  }
};