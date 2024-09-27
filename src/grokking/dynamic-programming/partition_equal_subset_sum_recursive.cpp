class Solution {
public:
  bool canPartition(vector<int> &nums) { return dfs(0, nums, 0, 0); }

private:
  bool dfs(int i, vector<int> nums, int leftSum, int rightSum) {
    int size = nums.size() - i;
    if (size <= 0)
      return leftSum == rightSum;
    return dfs(i + 1, nums, leftSum + nums[i], rightSum) ||
           dfs(i + 1, nums, leftSum, rightSum + nums[i]);
  }
};