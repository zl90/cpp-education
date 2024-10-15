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

class OptimalSolution {
public:
  int lengthOfLIS(vector<int> &nums) {
    vector<int> temp{nums[0]};
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] <= temp.back()) {
        // binary search to find first number that is >= nums[i]
        int a = 0, b = temp.size() - 1;
        while (a <= b) {
          int middle = (a + b) / 2;
          if (temp[middle] < nums[i]) {
            a = middle + 1;
          } else {
            b = middle - 1;
          }
        }
        temp[a] = nums[i];
      } else {
        temp.push_back(nums[i]);
      }
    }
    return temp.size();
  }
};