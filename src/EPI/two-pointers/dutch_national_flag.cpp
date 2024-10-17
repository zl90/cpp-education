class Solution {
public:
  void sortColors(vector<int> &nums) {
    if (nums.size() <= 1)
      return;
    int L = 0, R = nums.size() - 1, i = 0;
    while (i <= R) {
      if (nums[i] == 0) {
        swap(nums[i], nums[L]);
        L++;
      } else if (nums[i] == 2) {
        swap(nums[i], nums[R]);
        R--;
        i--;
      }
      i++;
    }
  }
};