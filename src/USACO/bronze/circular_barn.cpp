// https://usaco.org/index.php?page=viewproblem2&cpid=616

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> cows{N};

  for (int n = 0; n < N; n++) {
    cin >> cows[n];
  }

  int min_distance = INT_MAX;

  for (int n = 0; n < N; n++) {
    int cumulative_sum = 0;

    for (int i = 0; i < N; i++) {
      cumulative_sum += cows[i] * i;
    }

    min_distance = min(cumulative_sum, min_distance);

    // Rotate the elements to the right
    int last = cows[N - 1];
    for (int i = N - 1; i > 0; i--) {
      cows[i] = cows[i - 1];
    }
    cows[0] = last;
  }

  cout << min_distance;
}
