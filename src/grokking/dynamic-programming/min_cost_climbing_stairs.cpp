class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    int a = 0, b = 0;
    for (int i = 0; i < cost.size(); i++) {
      int c = min(a, b) + cost[i];
      a = b;
      b = c;
    }
    return min(a, b);
  }
};