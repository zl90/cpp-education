class Solution {
public:
  int rob(vector<int> &houses) {
    if (houses.empty())
      return 0;
    if (houses.size() == 1)
      return houses[0];
    if (houses.size() == 2)
      return max(houses[0], houses[1]);
    int a1 = houses[0], b1 = houses[1];
    for (int i = 2; i < houses.size() - 1; i++) {
      int c = houses[i] + a1;
      a1 = max(a1, b1);
      b1 = c;
    }
    int a2 = houses[1], b2 = houses[2];
    for (int i = 3; i < houses.size(); i++) {
      int c = houses[i] + a2;
      a2 = max(a2, b2);
      b2 = c;
    }
    return max({a1, b1, a2, b2});
  }
};