class SolutionBruteForce {
public:
  int maxProduct(vector<int> &nums) {
    if (nums.empty())
      return 0;
    if (nums.size() == 1)
      return nums[0];
    int maxProd = nums[0];
    for (int i = 0; i < nums.size(); i++) {
      int prod = 1;
      for (int j = i; j < nums.size(); j++) {
        prod *= nums[j];
        maxProd = max(prod, maxProd);
      }
    }
    return maxProd;
  }
};

class SolutionDP {
public:
  int maxProduct(vector<int> &nums) {
    if (nums.empty())
      return 0;
    // Kadanes algorithm --> learn this!
    int n = nums.size(), left = 1, right = 1, result = nums[0];
    for (int i = 0; i < n; i++) {
      if (left == 0) {
        left = 1;
      }
      if (right == 0) {
        right = 1;
      }
      left = left * nums[i];
      right = right * nums[n - 1 - i];
      result = max({result, left, right});
    }
    return result;
  }
};