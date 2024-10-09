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