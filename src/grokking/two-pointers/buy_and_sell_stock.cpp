class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() <= 1) return 0;
    int maxProfit = 0, a = 0;
    for (int b = 1; b < prices.size(); b++) {
      if (prices[b] < prices[a]) {
        a = b;
      } else {
        maxProfit = max(maxProfit, prices[b] - prices[a]);
      }
    }
    return maxProfit;
  }
};