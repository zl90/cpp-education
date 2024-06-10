// https://usaco.org/index.php?page=viewproblem2&cpid=963

#include <bits/stdc++.h>
using namespace std;

int main() {
  /*
  SAMPLE INPUT:

  3 4
  4 1 2 3
  4 1 3 2
  4 2 1 3

  --- DESK CHECKING:
  sessions:
    4 1 2 3

    4 1 3 2

    4 2 1 3
  i:^
  j:  ^

  pairs:[
      [{4,1}, {4,2}, {4,3}, {1,2}, {1,3}, {2,3}],
        ^
      [{4,1}, {4,2}, {4,3}, {1,2}, {1,3}, {3,2}],
        ^
      [{4,2}, {4,1}, {4,3}, {2,1}, {2,3}, {1,3}],
               ^
    ]

    result: {{4,1}, }

  */

  int K, N;
  cin >> K >> N;

  vector<vector<int>> sessions(K, vector<int>(N));

  for (int k = 0; k < K; k++) {
    for (int i = 0; i < N; i++) {
      cin >> sessions[k][i];
    }
  }

  vector<vector<pair<int, int>>> pairs(K);

  // Build each pair
  for (int k = 0; k < K; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        pairs[k].push_back({sessions[k][i], sessions[k][j]});
      }
    }
  }

  // Intersection on all sessions
  set<pair<int, int>> result;
  for (int k = 0; k < K; k++) {
    for (int i = 0; i < pairs[k].size(); i++) {
      bool is_intersection = true;

      // Search for matching element in every other session
      for (int x = k + 1; x < pairs.size(); x++) {
        bool has_found_matching_element = false;
        for (int j = 0; j < pairs[x].size(); j++) {
          if (pairs[k][i].first == pairs[x][j].first &&
              pairs[k][i].second == pairs[x][j].second) {
            has_found_matching_element = true;
            break;
          }
        }

        if (!has_found_matching_element) {
          is_intersection = false;
          break;
        }
      }

      if (is_intersection) {
        result.emplace(pairs[k][i]);
      }
    }
  }

  for (const auto& thing : result) {
    cout << "{" << thing.first << "," << thing.second << "}, ";
  }

  cout << result.size();
}
