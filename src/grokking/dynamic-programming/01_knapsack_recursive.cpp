
int dfs(int i, std::vector<int> &weights, std::vector<int> &values,
        int sumWeights, int sumValues, int C) {
  int size = weights.size() - i;
  if (size <= 0)
    return sumValues;
  if (size == 1) {
    if (sumWeights + weights[i] > C) {
      return sumValues;
    } else {
      return sumValues + values[i];
    }
  }
  if (sumWeights + weights[i] <= C) {
    return max(dfs(i + 1, weights, values, sumWeights + weights[i],
                   sumValues + values[i], C),
               dfs(i + 1, weights, values, sumWeights, sumValues, C));
  } else {
    return dfs(i + 1, weights, values, sumWeights, sumValues, C);
  }
}

int FindKnapsack(int capacity, std::vector<int> &weights,
                 std::vector<int> &values, int n) {
  return dfs(0, weights, values, 0, 0, capacity);
}