using namespace std;
#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];
    int a = 0, b = 0;
    for (int i = 0; i < nums.size(); i++) {
      int c = max(nums[i] + a, b);
      a = b;
      b = c;
    }
    return b;
  }
};