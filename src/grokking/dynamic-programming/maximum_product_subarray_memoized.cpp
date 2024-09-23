class Solution {
public:
  int maxProduct(vector<int> &nums) {
    if (nums.size() == 0)
      return 0;
    if (nums.size() == 1)
      return nums[0];
    unordered_map<int, int> cache;
    return dfs(0, 1, nums, false, cache);
  }

private:
  int dfs(int i, int product, vector<int> nums, bool isInSubArray,
          unordered_map<int, int> &cache) {
    int size = nums.size() - i;
    if (size <= 0 && !isInSubArray)
      return -2147483647 - 1;
    if (size <= 0 || product == 0)
      return product;
    if (isInSubArray) {
      return max(product * nums[i],
                 dfs(i + 1, product * nums[i], nums, true, cache));
    } else {
      return max({nums[i], dfs(i + 1, product * nums[i], nums, true, cache),
                  dfs(i + 1, product, nums, false, cache)});
    }
  }
};