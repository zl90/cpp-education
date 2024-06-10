// https://usaco.org/index.php?page=viewproblem2&cpid=736

#include <bits/stdc++.h>
using namespace std;

int main() {
  /*
SAMPLE INPUT:

3 8
AATCCCAT
GATTGCAA
GGTCGCAA
ACTCCCAG
ACTCGCAT
ACTTCCAT

--- DESK CHECKING:
spotty_chars: {}

*/

  int N, M;
  cin >> N >> M;

  vector<vector<char>> spotty_sequences(N, vector<char>(M));
  vector<vector<char>> plain_sequences(N, vector<char>(M));

  for (auto& sequence : spotty_sequences) {
    for (auto& character : sequence) {
      cin >> character;
    }
  }

  for (auto& sequence : plain_sequences) {
    for (auto& character : sequence) {
      cin >> character;
    }
  }

  int count = 0;

  for (int i = 0; i < M; i++) {
    unordered_map<char, bool> spotty_chars;
    unordered_map<char, bool> plain_chars;

    for (int j = 0; j < N; j++) {
      spotty_chars[spotty_sequences[j][i]] = true;
      plain_chars[plain_sequences[j][i]] = true;
    }

    bool is_disjoint = true;
    for (auto [plain_char, value] : plain_chars) {
      if (spotty_chars.find(plain_char) != spotty_chars.end()) {
        is_disjoint = false;
        break;
      }
    }
    if (is_disjoint) {
      count++;
    }
  }

  cout << count;
}
