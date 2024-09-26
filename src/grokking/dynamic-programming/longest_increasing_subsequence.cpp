class DynamicProgrammingSolution {
public:
  int lengthOfLIS(vector<int> &nums) {
    if (nums.size() <= 1)
      return nums.size();
    vector<int> lengths(nums.size(), 1);
    int maxLength = 1;
    for (int i = 1; i < nums.size(); i++) {
      int curr = nums[i];
      int nextLargestLength = 1;
      bool nextSmallestFound = false;
      for (int j = 0; j < i; j++) {
        if (nums[j] < curr) {
          nextLargestLength = max(nextLargestLength, lengths[j]);
          nextSmallestFound = true;
        }
      }
      if (nextSmallestFound) {
        lengths[i] = nextLargestLength + 1;
        maxLength = max(maxLength, lengths[i]);
      }
    }
    return maxLength;
  }
};