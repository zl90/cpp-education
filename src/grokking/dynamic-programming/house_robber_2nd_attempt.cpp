class Solution {
public:
  int rob(vector<int> &nums) {
    int a = 0, b = 0;
    for (int i = 0; i < nums.size(); i++) {
      int c = a + nums[i];
      a = max(a, b);
      b = c;
    }
    return max(a, b);
  }
};