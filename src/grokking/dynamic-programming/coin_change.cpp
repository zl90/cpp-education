class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    if (amount == 0)
      return 0;
    vector<int64_t> dp(amount + 1, 0);
    for (int64_t i = amount - 1; i >= 0; i--) {
      vector<int64_t> validPositions;
      for (int64_t j = 0; j < coins.size(); j++) {
        if (coins[j] + i <= amount && dp[coins[j] + i] > -1) {
          validPositions.push_back(coins[j] + i);
        }
      }
      if (validPositions.empty()) {
        dp[i] = -1;
      } else {
        // find the valid position with the minimum number of coins required to
        // reach the end
        dp[i] = 1 + dp[validPositions[0]];
        for (int64_t j = 1; j < validPositions.size(); j++) {
          dp[i] = min(dp[i], 1 + dp[validPositions[j]]);
        }
      }
    }
    return dp[0];
  }
};