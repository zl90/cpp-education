// https://usaco.org/index.php?page=viewproblem2&cpid=1228

#include <bits/stdc++.h>
using namespace std;

int main() {
  /*
    SAMPLE INPUT:

    2
    G 3
    L 5

  */

  int N;
  cin >> N;

  vector<pair<char, int>> cows;
  int max_value = 0;

  for (int i = 0; i < N; i++) {
    char direction;
    int value;
    cin >> direction >> value;
    max_value = max(max_value, value);
    cows.push_back({direction, value});
  }

  int min_liars = cows.size();

  for (int i = 0; i <= max_value; i++) {
    int liar_count = 0;
    for (const auto& [direction, value] : cows) {
      if ((direction == 'G' && value > i) || (direction == 'L' && value < i)) {
        liar_count++;
      }
    }
    min_liars = min(min_liars, liar_count);
  }

  cout << min_liars;
}
