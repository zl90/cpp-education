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
    if (size <= 0 || product == 0)
      return product;
    if (cache.find(i) != cache.end()) {
      return cache[i];
    }
    if (isInSubArray) {
      cache[i] = max(product * nums[i],
                     dfs(i + 1, product * nums[i], nums, true, cache));
    } else {
      cache[i] = max(dfs(i + 1, product * nums[i], nums, true, cache),
                     dfs(i + 1, product, nums, false, cache));
    }
    return cache[i];
  }
};