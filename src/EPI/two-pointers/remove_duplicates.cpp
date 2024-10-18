class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    if (nums.size() <= 1)
      return nums.size();
    int a = 1;
    for (int b = 0; b < nums.size(); b++) {
      if (nums[a - 1] != nums[b]) {
        nums[a] = nums[b];
        a++;
      }
    }
    return a;
  }
};