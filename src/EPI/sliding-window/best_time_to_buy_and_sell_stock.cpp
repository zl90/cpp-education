class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.size() <= 1)
      return 0;
    int a = 0, maxProfit = 0;
    for (int b = 0; b < prices.size(); b++) {
      if (prices[b] - prices[a] < 0) {
        a = b;
      }
      maxProfit = max(maxProfit, prices[b] - prices[a]);
    }
    return maxProfit;
  }
};