class SolutionKadanesAlgo {
public:
  int maxSubArray(vector<int> &nums) {
    if (nums.empty())
      return 0;
    if (nums.size() == 1)
      return nums[0];
    int res = INT_MIN, sum = 0;
    for (const auto &num : nums) {
      if (sum <= 0) {
        sum = num;
      } else {
        sum += num;
      }
      res = max({res, num, sum});
    }
    return res;
  }
};