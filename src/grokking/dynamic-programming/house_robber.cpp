#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];
    unordered_map<int, int> cache;
    return max(robHouses(2, nums, cache) + nums[0],
               robHouses(3, nums, cache) + nums[1]);
  }

 private:
  int robHouses(int i, vector<int> nums, unordered_map<int, int>& cache) {
    int size = nums.size() - i;
    if (size <= 0) return 0;
    if (size == 1) return nums[i];
    if (size == 2) return max(nums[i], nums[i + 1]);
    if (size == 3) return max(nums[i + 1], nums[i] + nums[i + 2]);
    if (cache[i] > 0) return cache[i];
    cache[i] = max(robHouses(i + 2, nums, cache) + nums[i],
                   robHouses(i + 3, nums, cache) + nums[i + 1]);
    return cache[i];
  }
};